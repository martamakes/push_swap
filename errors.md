Build complete! 🚀
(.venv) event@c2r19s5:~/Downloads/push_swap-main$ ./push_swap 1 3 2
rra
sa
(.venv) event@c2r19s5:~/Downloads/push_swap-main$ make get-tools
Compiling for Linux. Use valgrind for memory checks
Downloading testing tools...
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
100  1260  100  1260    0     0   4172      0 --:--:-- --:--:-- --:--:--  4186
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
100 10144  100 10144    0     0  43542      0 --:--:-- --:--:-- --:--:-- 43724
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
100  8733  100  8733    0     0  28993      0 --:--:-- --:--:-- --:--:-- 28917
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
100 70928  100 70928    0     0   212k      0 --:--:-- --:--:-- --:--:--  212k
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
100 38192  100 38192    0     0   127k      0 --:--:-- --:--:-- --:--:--  127k
Testing tools downloaded successfully!
(.venv) event@c2r19s5:~/Downloads/push_swap-main$ ./push_swap 1 3 2 | ./checker_linux 1 3 2
OK
(.venv) event@c2r19s5:~/Downloads/push_swap-main$ make bonus
Compiling for Linux. Use valgrind for memory checks
Compiling src/bonus/checker_bonus.c...
Building checker...
Checker build complete! 🎯
(.venv) event@c2r19s5:~/Downloads/push_swap-main$ ./push_swap 1 3 2
rra
sa
(.venv) event@c2r19s5:~/Downloads/push_swap-main$ ./checker
(.venv) event@c2r19s5:~/Downloads/push_swap-main$ ./checker 1 3 2
^Z
[1]+  Stopped                 ./checker 1 3 2
(.venv) event@c2r19s5:~/Downloads/push_swap-main$ ./checker 10
^Z
[2]+  Stopped                 ./checker 10
(.venv) event@c2r19s5:~/Downloads/push_swap-main$ ARG="1 3 2"; ./push_swap $ARG | ./checker $ARG
OK
(.venv) event@c2r19s5:~/Downloads/push_swap-main$ ./push_swap 1 3 2 | ./checker_linux 1 3 2
OK
(.venv) event@c2r19s5:~/Downloads/push_swap-main$ ./checker_linux 1 3 2
sa
pb
KO
(.venv) event@c2r19s5:~/Downloads/push_swap-main$ ./checker_linux 1 3 2 27 -69 83
rra
sa
pb
pb
sb
pa
pa
KO
(.venv) event@c2r19s5:~/Downloads/push_swap-main$ ARG="1 3 2 27 -69 83"; ./push_swap $ARG | ./checker $ARG
Error
(.venv) event@c2r19s5:~/Downloads/push_swap-main$ ./push_swap 1 3 2 27 -69 83 | ./checker_linux 1 3 2 27 -69 83
OK
(.venv) event@c2r19s5:~/Downloads/push_swap-main$ ARG="1 3 2 27 -69"; ./push_swap $ARG | ./checker $ARG
Error
(.venv) event@c2r19s5:~/Downloads/push_swap-main$ ARG="1 3 2 27"; ./push_swap $ARG | ./checker $ARG
OK
(.venv) event@c2r19s5:~/Downloads/push_swap-main$ ARG="1 3 2 -27"; ./push_swap $ARG | ./checker $ARG
Error
(.venv) event@c2r19s5:~/Downloads/push_swap-main$ ARG="1 3 2 27 69"; ./push_swap $ARG | ./checker $ARG
Error
(.venv) event@c2r19s5:~/Downloads/push_swap-main$ ARG="1 3 2 4 5"; ./push_swap $ARG | ./checker $ARG
Error
(.venv) event@c2r19s5:~/Downloads/push_swap-main$ ARG="1 3 2 4"; ./push_swap $ARG | ./checker $ARG
Error
(.venv) event@c2r19s5:~/Downloads/push_swap-main$ ARG="1 3"; ./push_swap $ARG | ./checker $ARG
OK
(.venv) event@c2r19s5:~/Downloads/push_swap-main$ ARG="1 3 2"; ./push_swap $ARG | ./checker $ARG
OK
(.venv) event@c2r19s5:~/Downloads/push_swap-main$ ARG="13 2"; ./push_swap $ARG | ./checker $ARG
Error
(.venv) event@c2r19s5:~/Downloads/push_swap-main$ ARG="13 2 27"; ./push_swap $ARG | ./checker $ARG
OK
(.venv) event@c2r19s5:~/Downloads/push_swap-main$ ARG="2 27"; ./push_swap $ARG | ./checker $ARG
OK
(.venv) event@c2r19s5:~/Downloads/push_swap-main$ ARG="2 27 13 13"; ./push_swap $ARG | ./checker $ARG
EErrrroorr
