# Auto code review

[![codebeat badge](https://codebeat.co/badges/0575b6b5-c450-49c5-b66e-6f4e0b09adac)](https://codebeat.co/projects/github-com-kacper-ragankiewicz-coding-university-main)

[![Codacy Badge](https://app.codacy.com/project/badge/Grade/2119bff7ed5645f4ba4313772aff14de)](https://app.codacy.com/gh/kacper-ragankiewicz/coding-university/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade)


<br/>


# Tracking your progress in *coding-interview-university* with Github.

## ***>>> Script doesn't work if you don't stay in track daily!!***

# **How to run it**

Script is written in C++

To compile it from .cpp, you need to have gcc installed.

check gcc:

```
$ gcc -v
```

or just run it using:

```
$ chmod +x main & ./main
```
# **Starting your count**
*If you don't have git, program will still works, but without synchronization.*
### Init new repo with git init and push it to your Github.


After first git push, every time when you run script, changes while automatically synchronize.

```
$ sudo rm -r .git/
$ git init
$ git remote add origin git@github.com:<YOUR_NAME>/<NAME_OF_YOUR_REPO>.git
$ git branch -M main
$ git add .
$ git commit -m "First init"
$ git push -u origin main
```

*To get new or other coding-university.md, visit  [jwasham / coding-interview-university](https://github.com/jwasham/coding-interview-university)*

# **How to use it**

### After marking on coding_university.md from "- [_]" to "- [X]", run the script.

The script will compare the value with the previous days and will tell you with such an average per day how many days you have left until the end of the coding_university.md.

Print at the end something similar to this:
```
>>> You have done: 80 and there is: 420 left.
>>> You do average: 3 per day, and in that speed, you will finish in: 4 months.
```


# **Architecture**

**main** *- exe file for linux*

**main.cpp** *- its main c++ script where you can make changes*


**coding_university.md** *- this is the source md file (you swap it with your file and progress)*

**data.txt** *- it's where your date with progress is stored*

**This is the extension of [jwasham / coding-interview-university](https://github.com/jwasham/coding-interview-university)**



