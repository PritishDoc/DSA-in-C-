const robot = require("robotjs");

setInterval(() => {
  const { x, y } = robot.getMousePos();
  robot.moveMouse(x + 1, y); // move slightly
  robot.moveMouse(x, y);     // return to original position
}, 5000); // every 5 seconds
