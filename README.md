# LAB03 - Recursive Implementation of Bag Operations

Recursive implementations of helper methods are developed to support the 
`BagInterface` API implemented by a new class named `ArrayBagRecursive`.

## Background

Before proceeding with this lab, the student should take the time to read

* [C++ Interlude 1 C++ Classes](https://msu.vitalsource.com/reader/books/9780138122782/epubcfi/6/46%5B%3Bvnd.vst.idref%3DP70010183410000000000000000009FA%5D!/4/2%5BP70010183410000000000000000009FA%5D/2/2%5BP70010183410000000000000000009FB%5D/7:0%5B%2C%20C%2B%5D)
* [Chapter 2 Bags](https://msu.vitalsource.com/reader/books/9780138122782/epubcfi/6/62%5B%3Bvnd.vst.idref%3DP7001018341000000000000000000CEA%5D!/4/2%5BP7001018341000000000000000000CEA%5D/2/2%5BP7001018341000000000000000000CEB%5D/7:0%5B%2CBag%5D)
* [Chapter 3 Array-Based Implementations](https://msu.vitalsource.com/reader/books/9780138122782/epubcfi/6/74%5B%3Bvnd.vst.idref%3DP7001018341000000000000000000EC1%5D!/4/2%5BP7001018341000000000000000000EC1%5D/2/2%5BP7001018341000000000000000000EC2%5D/7:0%5B%2C%20Ar%5D)

## Objective

Upon successful completion of this lab, the student has learned how to

* declare `private` helper member functions used to support a public interface
* use recursion to process arrays to 
  * determine if a given item is found in the given array
  * count the number of occurrences of some item in the given array

## Getting Started

After accepting this assignment with the provided GitHub Classroom 
Assignment Link, decide how you want to work with your newly created repository:

- Using Codespaces directly in your web browser that employees the Visual Studio Code online IDE, or
- Using the IDE of your choice on your local machine

### Codespaces

If a Codespace is available for use (and this is your preferred method of development), open your newly created repository in a Codespace.

At this point, you can skip to [Creating a development branch](#creating-a-development-branch).

### Local Development

Depending upon the IDE of your choice, many of the following steps may be taken within your IDE. It is up to you to discover these tools (assuming they're available) and learn how to use them appropriately as desired. The following instructions are assumed to take place within a terminal window. Note: many IDEs provide a terminal window as well.

#### Cloning your repository

The command you use to clone is slightly different depending upon whether 
you're using `git` via `https`, `ssh`, or using the GitHub Cli via `gh`.

If you're using the `https` protocol, your clone command is:

```shell
git clone https://github.com/msu-csc232-sp25/<repo-name>.git
```

If you're using the `ssh` protocol, your clone command is:

```shell
git clone git@github.com:msu-csc232-sp25/<repo-name>.git
```

Finally, if you're using the GitHub CLI (`gh`), your clone command is:

```shell
gh repo clone msu-csc232-sp25/<repo-name>
```

After cloning the repository, navigate into the newly cloned repository:

```shell
cd <repo-name>
```

#### Creating a development branch

Next, create a branch named `develop`. Please note: The name of this branch **must** be as specified and will be, to the grading scripts, case-sensitive.

```shell
git checkout -b develop
```

Make sure you are on the `develop` branch before you get started. Make all your commits on the `develop` branch.

```bash
git status
```

_You may have to type the `q` character to get back to the command line prompt after viewing the status._

## Tasks

This lab consists of three tasks:

- Task 1: Declare private recursive helper methods
- Task 2: Implement `getIndexOf` recursively
- Task 3: Implement `countFrequency` recursively

### Task 1: Declare private recursive helper methods

In this first task, you'll declare two helper methods that will be employed 
by three different public methods inherited from the `BagInterface`.

1. Locate the `TEST_TASK1` macro definition in the `csc232.h` header file 
   and toggle its definition from `FALSE` to `TRUE`.
2. Locate the `TODO: Task 1a` comment in the `ArrayBagRecursive.h` header file 
   and declare a `private` method named `getIndexOf` that returns an `int` and 
   has two parameters. The first  parameter is the target item passed by 
   `const` reference and the second parameter is an `index` into the `items` 
   array where we hope to find the target. Name the first parameter `target` 
   and the second parameter `searchIndex`.
3. Locate the `TODO: Task 1b` comment in the `ArrayBagRecursive.h` header file 
   and declare a `private` method named `countFrequency` that returns an `int` 
   and has two parameters. The first parameter is the target item passed by 
   `const` reference and the second parameter is an `index` into the `items` 
   array where we hope to find the target item whose frequency we are 
   counting. Name the first parameter `anEntry` and the second parameter 
   `searchIndex`.
4. When you have completed these steps, execute the `task1_test` target to 
   validate your work. Once you are pleased with the results of the unit 
   tests, stage, commit, and push your changes to GitHub.

### Task 2: Implement `getIndexOf` recursively

Below is a simple algorithm for locating the index of some target in an
array recursively.

```text
initialize result to -1
if have not visited every item in the array yet
    if we are currently looking at the target
        return the current index
    else
        we have not found the target yet, so keep looking
        at the rest of the data
        result = index of target in the remaining items <-- recursive call
return result
```

What do we know?

* The items in an `ArrayBagRecursive` are stored in an array in the same
  manner as we found in the `ArrayBag`, namely, in a "packed" manner located
  in indexes 0 up to `itemCount`. (Recall, `itemCount` is the index of the
  next available location for an item.)
* When we write a function that processes an array, we need to pass both the
  array and at least one other parameter that advances through the array
  with each recursive iteration
* As long as this other parameter is less than `itemCount`, we have an index
  of a valid item in our bag.

In this task, you'll use the given pseudocode, along with these facts, to
devise a recursive algorithm for locating the index of some target in
the array of items maintained by this bag interface implementation.

#### Steps

1. Locate the `TEST_TASK2` macro definition in the `csc232.h` header file 
   and toggle its definition from `FALSE` to `TRUE`.
2. Locate the `TODO: Task 2a - Implement me accordingly` comment in the 
   `ArrayBagRecursive.cpp` source file and implement this helper method 
   accordingly (using the above pseudocode and the given facts as a guide, 
   if necessary).
3. When you have completed step 2, locate the `TODO: Task 2b` comment and
   have the `remove` method call `getIndexOf` as needed and prescribed in 
   the comment.
4. Next, locate the `TODO: Task 2c` comment and have the `contains` method 
   call `getIndexOf` as needed and prescribed in the comment.
5. Once you have completed these steps, execute the `task2_test` target.
   When you are happy with the results of the unit tests, stage, commit, and
   push your changes to GitHub.

### Task 3: Implement `countFrequency` recursively

Below is a simple algorithm for counting the frequency of some target in an
array recursively.

```text
initialize frequency to 0
if have not visited every item in the array yet
    if we are currently looking at the target
        frequency = 1 + frequency of target in the remaining items <-- 
        recursive call
    else
        we have not found the target yet, so keep looking
        at the rest of the data
        frequency = frequency of target in the remaining items <-- recursive 
        call
return frequency
```

What do we know?

* The items in an `ArrayBagRecursive` are stored in an array in the same
  manner as we found in the `ArrayBag`, namely, in a "packed" manner located
  in indexes 0 up to `itemCount`. (Recall, `itemCount` is the index of the
  next available location for an item.)
* When we write a function that processes an array, we need to pass both the
  array and at least one other parameter that advances through the array
  with each recursive iteration
* As long as this other parameter is less than `itemCount`, we have an index
  of a valid item in our bag.

In this task, you'll use the given pseudocode, along with these facts, to
devise a recursive algorithm for counting the frequency of some target in
the array of items maintained by this bag interface implementation.

#### Steps

1. Locate the `TEST_TASK3` macro definition in the `csc232.h` header file 
   and toggle its definition from `FALSE` to `TRUE`.
2. Locate the `TODO: Task 3a - Implement me accordingly` comment in the 
   `ArrayBagRecursive.cpp` source file and implement this helper method 
   accordingly (using the above pseudocode and the given facts as a guide, 
   if necessary).
3. When you have completed step 2, locate the `TODO: Task 3b` comment and
   have the `getFrequencyOf` method call `countFrequency` accordingly.
4. Once you have completed these steps, execute the `task3_test` target.
   When you are happy with the results of the unit tests, stage, commit, and
   push your changes to GitHub.

## Submission Details

Before submitting your assignment, be sure you have pushed all your changes to GitHub. If this is the first time you're pushing your changes, the push command will look like:

```bash
git push -u origin develop
```

If you've already set up remote tracking (using the `-u origin develop` switch), then all you need to do is type

```bash
git push
```

As usual, prior to submitting your assignment on Brightspace, be sure that you have committed and pushed your final changes to GitHub. Once your final changes have been pushed, create a pull request that seeks to merge the changes in your `develop` branch into your `trunk` branch.

You can use `gh` to create this pull request right from your command-line prompt:

```bash
gh pr create --assignee "@me" --title "Some appropriate title" --body "A message to populate description, e.g., Go Bills!" --head develop --base trunk --reviewer msu-csc232-fa24/graders
```

An "appropriate" title is at a minimum, the name of the assignment, e.g., `LAB02` or `HW04`, etc.

Once your pull request has been created, submit the URL of your assignment _repository_ (i.e., _not_ the URL of the pull request) as a Text Submission on Brightspace. Please note: the timestamp of the submission on Brightspace is used to assess any late penalties if and when warranted, _not_ the date/time you create your pull request. **No exceptions will be granted for this oversight**.

### Due Date

Your assignment submission is due by 11:59 PM, Saturday, February 22, 2025.

### Grading Rubric

This assignment is worth **3 points**.

| Criteria           | Exceeds Expectations         | Meets Expectations                  | Below Expectations                  | Failure                                        |
|--------------------|------------------------------|-------------------------------------|-------------------------------------|------------------------------------------------|
| Pull Request (20%) | Submitted early, correct url | Submitted on-time; correct url      | Incorrect URL                       | No pull request was created or submitted       |
| Code Style (20%)   | Exemplary code style         | Consistent, modern coding style     | Inconsistent coding style           | No style whatsoever or no code changes present |
| Correctness^ (60%) | All unit tests pass          | At least 80% of the unit tests pass | At least 60% of the unit tests pass | Less than 50% of the unit tests pass           |

^ _The Google Test unit runner will calculate the correctness points based purely on the fraction of tests passed_.

### Late Penalty

* In the first 24-hour period following the due date, this lab will be penalized 0.6 points meaning the grading starts at 2.4 (out of 3.0 total possible) points.
* In the second 24-hour period following the due date, this lab will be penalized 1.2 points meaning the grading starts at 1.8 (out of 3.0 total possible) points.
* After 48 hours, the assignment will not be graded and thus earns no points, i.e., 0.0 out of 3.0 possible points.

## Disclaimer & Fair Use Statement

This repository may contain copyrighted material, the use of which may not
have been specifically authorized by the copyright owner. This material is
available in an effort to explain issues relevant to the course or to
illustrate the use and benefits of an educational tool. The material
contained in this repository is distributed without profit for research and
educational purposes. Only small portions of the original work are being
used and those could not be used to easily duplicate the original work.
