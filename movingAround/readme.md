# Moving Around

Second task. A really interesting one:
complete a routine of picking up and dropping a ball with the robot.
Although fun, the part I didn't like was the fact that
it relied on something that is extremely unreliable: humans.

To complete the routine,
someone would need to set up the robot exactly 1 metre away from the ball.
To me, that seems extremely error-prone.
If someone were to set up the robot just a couple of centimetres too close
or too far, the program might fail.

Same with the claw,
someone must read either this or the comments and set it up initially
in the fully open position for the program to work.
To solve this a lot of people set the motor to spin the entire length from
fully closed to open every time the program is ran.
However,
if the claw is not initially in a closed position,
that will cause the motor to over-rotate and
thus potentially overheat and stall the program.

I tried solving this issue by reading the encoder data on the motor of the claw.
However, although I had success reading the degree,
I soon realized that the values reset at the end of each program.
Therefore, you would always start with
0 degrees, hence rendering the data useless for this purpose.

All in all, still a fun task with _a lot_ of trial and error.
Very proud it finally worked!
