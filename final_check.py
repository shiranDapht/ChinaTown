#!/usr/bin/env python3
'''Helper script for checking that a submission ZIP file:
- contains all the necessary files
- does not contain unnecessary files
- compiles correctly (with provided files)
- passes basic tests
'''

import glob
import os
import shutil
import subprocess
import sys
import tempfile
import zipfile
import difflib

### settings: assignement files ###
PROVIDED_TEST_FILES = ['city_test.cpp', 'city_test_output.txt',
                       'employee_print_test.cpp', 'employee_print_output.txt',
                        'manager_print_test.cpp', 'manager_print_output.txt',
                        'workplace_print_test.cpp','workplace_print_output.txt']
TESTS_DIR = 'provided'
PROVIDED_MISC_FILES = ['final_check.py']
PROVIDED_FILES = PROVIDED_TEST_FILES + PROVIDED_MISC_FILES
PROVIDED_FILES_DIR = os.path.dirname(__file__)

# add files name cpp + h
MINIMUM_REQUIRED_TOP_DIR_FILES = ['Citizen.cpp', 'City.h', 'Employee.h', 'Manager.cpp', 'Skill.h', 'Citizen.h',
                                  'exceptions.h', 'Manager.h', 'Workplace.cpp', 'City.cpp', 'Employee.cpp', 'Faculty.h',
                                  'Skill.cpp', 'Workplace.h']
MINIMUM_REQUIRED_TOP_DIR_FILES_CASE_INSENSITIVE = ['dry.pdf']

### settings: compilation ###

BASIC_GCC_ARGS = ['-std=c++11', '-g', '-Wall', '-Werror', '-pedantic-errors']

PART1_NAME = 'solution'
EXEC_NAME_PART1 = 'solution'
GCC_ARGS_PART1 = BASIC_GCC_ARGS.copy()
# list of pairs: (subdirectory, glob pattern)
GCC_SOURCES_PART1 = [('', '*.cpp')]


def main():
    if len(sys.argv) != 2:
        print("Usage: %s <zipfile>" % sys.argv[0])
        return
    with tempfile.TemporaryDirectory() as path:
        print("Extracting zip to temporary folder:", path)
        zip_ref = zipfile.ZipFile(sys.argv[1], 'r')
        zip_ref.extractall(path)
        zip_ref.close()

        for root, _, files in os.walk(os.path.join(path, 'solution')):  # replace the . with your starting directory
            for file in files:
                path_file = os.path.join(root, file)
                shutil.copy2(path_file, path)

        shutil.rmtree(os.path.join(path, 'solution'))

        if not check_folder(path):
            print("Submission has errors, please fix.")
            return

        copy_provided_files(path)

        if not build_and_test(path):
            print("Submission has errors, please fix.")
            return
        print("Congratulations, you passed the provided tests!!!")


def check_folder(path):
    print("Verifying contents...")
    files = os.listdir(path)
    found_errors = check_folder_contents(files,
                                         MINIMUM_REQUIRED_TOP_DIR_FILES,
                                         MINIMUM_REQUIRED_TOP_DIR_FILES_CASE_INSENSITIVE,
                                         PROVIDED_FILES)
    if found_errors:
        print("There are errors in contents of the ZIP file.")
    else:
        print("The ZIP file contains all the necessary files.")
    return not found_errors


def check_folder_contents(contents, required_files, required_files_case_insensitive,
                          forbidden_files, prefix=''):
    found_errors = False
    for filename in required_files:
        pretty_name = os.path.join(prefix, filename)
        if filename in contents:
            print('Found required file/directory:', pretty_name)
        else:
            found_errors = True
            print('ERROR: Missing required file/directory:', pretty_name)

    for filename in required_files_case_insensitive:
        pretty_name = os.path.join(prefix, filename)
        if filename.lower() in map(str.lower, contents):
            print('Found required file/directory:', pretty_name)
        else:
            found_errors = True
            print('ERROR: Missing required file/directory:', pretty_name)

    for filename in forbidden_files:
        if filename in contents:
            found_errors = True
            print('ERROR: Found provided file/directory:', os.path.join(prefix, filename))

    for filename in contents:
        pretty_name = os.path.join(prefix, filename)
        if (filename in required_files or
                filename in forbidden_files or
                filename.lower() in required_files_case_insensitive):
            # already checked above
            continue

        if filename.endswith('.cpp') or filename.endswith('.h') or filename.endswith('.hpp'):
            print('Found file:', pretty_name)
            continue

        found_errors = True
        print('ERROR: Found unexpected file/directory:', pretty_name)

    return found_errors


def copy_provided_files(dst_dir):
    dst_tests_dir = os.path.join(dst_dir, TESTS_DIR)
    os.makedirs(dst_tests_dir)
    for f in PROVIDED_TEST_FILES:
        shutil.copy(os.path.join(PROVIDED_FILES_DIR, TESTS_DIR, f), dst_tests_dir)


def relative_glob(pattern, path, subdir=''):
    return [os.path.join(subdir, os.path.basename(f)) for f in
            glob.glob(os.path.join(path, subdir, pattern))]


def build_and_test(path):
    part1_sources = sum([relative_glob(pattern, path, subdir=subdir)
                         for (subdir, pattern) in GCC_SOURCES_PART1],
                        [])
    for i in range(0,4):
        test_i = TESTS_DIR + '/' +PROVIDED_TEST_FILES[2*i]
        part1_sources.append(test_i)
        part1_compiled = compile_test(path, PART1_NAME, EXEC_NAME_PART1,
                                    GCC_ARGS_PART1 + part1_sources)
        part1_sources.pop()
        if not (part1_compiled):
            return False
        if not run_test(path, PART1_NAME, EXEC_NAME_PART1, 2*i):
            return False
        print(PROVIDED_TEST_FILES[2*i] + ' passed!!')
    return True


def compile_test(path, test_name, exec_file, gcc_args):
    command = ['g++'] + gcc_args + ['-o', exec_file]
    print("Compiling %s... (command: %s)" % (test_name, ' '.join(command)))
    if subprocess.call(command, shell=False, cwd=path):
        print("ERROR: couldn't compile %s" % test_name)
        return False
    return True


def run_test(path, test_name, exec_file, i):
    print("Testing %s..." % PROVIDED_TEST_FILES[i])
    proc = subprocess.Popen(os.path.join('.', exec_file), shell=False, cwd=path,
                            stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                            universal_newlines=True)
    out, _ = proc.communicate()
    with open(os.path.join(path, 'provided', PROVIDED_TEST_FILES[i+1])) as f:
        expected_out = f.read()
    # Find and print the diff:
    for line in difflib.unified_diff(out, expected_out, fromfile='file1', tofile='file2', lineterm=''):
        print(out)
        return False

    if proc.returncode != 0:
        print("ERROR: %s test errored" % test_name)
        return False
    if 'FAIL' in out or 'Failed' in out:
        print("ERROR: %s test failed" % test_name)
        return False
    return True


if __name__ == '__main__':
    main()
