# Introduction
The `abstract-fps` application is a simple FPS-style tool designed to help study frame rate, latency, and other effects in a controlled environment. The application is implemented in the [G3D Innovation Engine](https://casual-effects.com/g3d/www/index.html) and requires the latest version of G3D to be run. All additional resources required to run the application are included in this git repository.

The application implements a simple mouse-controlled view model with a variety of parameters controllable through various `.Any` files (more on this below). The scene, weapon, target size/behavior, and frame rate/latency controls are all available via this interface.

# Parameter Files
As mentioned above a variety of `.Any` files (similar to JSON file format) are used to control the behavior of the application. These files are as follows:

* [`startupconfig.Any`](./data-files/startupConfigReadme.md) is a simple configuration file for setting the `playMode` (debug feature) and pointing to the experiment and user configs
* [`experimentconfig.Any`](./data-files/experimentConfigReadme.md) is the primary configuration for the experiment. It includes scene, target, and weapon information and also establishes the sessions to take place during the experiment
* [`userconfig.Any`](./data-files/userConfigReadme.md) holds user information for (multiple) users including mouse sensitivity and DPI
* [`userstatus.Any`](./data-files/userStatusReadme.md) keeps track of both the session ordering and the completed sessions for any given user
* [`weaponconfig.Any`](./data-files/weapon/weaponConfigReadme.md) can be optionally included (using the `#include("filename")` option in the .Any format) to allow quick swap of weapons across multiple configs