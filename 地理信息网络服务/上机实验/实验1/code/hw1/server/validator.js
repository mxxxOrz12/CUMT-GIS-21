const fs = require("fs");
const net = require("net");

class NodeSetupError extends Error {}
let routeChecked = false;

function checkHotLoader() {
  return new Promise((resolve, reject) => {
    var server = net.createServer();

    server.once("error", (err) => {
      resolve(err.code === "EADDRINUSE");
    });

    server.once("listening", () => server.close());
    server.once("close", () => resolve(false));
    server.listen(5050);
  });
}

module.exports = {
  checkSetup: () => {
    if (!fs.existsSync("./node_modules/")) {
      throw new NodeSetupError(
        "node_modules not found! This probably means you forgot to run 'npm install'"
      );
    }
  },

  checkRoutes: (req, res, next) => {
    if (!routeChecked && req.url === "/") {
      if (!fs.existsSync("./client/dist/bundle.js")) {
        throw new NodeSetupError(
          "Couldn't find bundle.js! If you want to run the hot reloader, make sure 'npm run hotloader'\n" +
            "is running and then go to http://localhost:5050 instead of port 3000.\n" +
            "If you're not using the hot reloader, make sure to run 'npx webpack' before visiting this page"
        );
      }

      checkHotLoader().then((active) => {
        if (active) {
          console.log(
            "Warning: It looks like 'npm run hotloader' may be running. Are you sure you don't want\n" +
              "to use the hot reloader? To use it, visit http://localhost:5050 and not port 3000"
          );
        }
      });

      routeChecked = true;
    }
    next();
  },
};
