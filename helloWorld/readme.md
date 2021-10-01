# Hello World

First task.
This fetches all the brain statistics then updates them when the button is pressed.
The button is really not necessary, but it's a nice proof of concept.

**Problems:**

- `Brain.Screen.newLine()` is annoying, I wish I can just use `\n`.

- Cannot properly round `double` that is returned with battery `voltage()` and `current()`.
  It currently shows six decimals; hence, I would like to round it down.
  However, I don't understand the decimal types well enough.
  I need to use some math to round it then format it into `Brain.Screen.print()`.

- Initially, my idea was to switch to a different statistic every time the button is pressed.
  However, the `Brain.Screen.pressing()` doesn't just trigger as one event;
  rather, it keeps on triggering as long as it is pressed.
  Because so, the `brain` just quickly shuffles through all the stats without really having enough time to read any one.
  The `Brain.Screen.pressed()` seems to report just one event. However, I don't exactly know how to use it with the callback.
