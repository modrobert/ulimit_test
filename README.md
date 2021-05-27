# ulimit_test

### Copyright (C) Robert &lt;modrobert@gmail.com&gt;
### Software licensed under Zero Clause BSD.

---

### Description

Example C program to set soft open files limit (ulimit).

---

### Usage

<pre>
$ ./ulimit_test
</pre>

---

### Example output.

<pre>
Open files soft limit: 1024
Open files hard limit: 1048576
Max open files for this process set to: 10000
Open files soft limit: 10000
Open files hard limit: 1048576
</pre>

---

### Build

Use 'make' or compile manually with:
gcc -Wpedantic ulimit_test.c -o ulimit_test

