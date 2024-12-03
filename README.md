<p align="center">
	<img src="data:image/svg+xml;base64,PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0idXRmLTgiPz4KICAgIDxzdmcgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIiB2aWV3Qm94PSIwIDAgODAwIDIwMCI+CiAgICAgICAgPGRlZnM+CiAgICAgICAgICAgIDxsaW5lYXJHcmFkaWVudCBpZD0iYmctZ3JhZGllbnQiIHgxPSIwJSIgeTE9IjAlIiB4Mj0iMTAwJSIgeTI9IjEwMCUiPgogICAgICAgICAgICAgICAgPHN0b3Agb2Zmc2V0PSIwJSIgc3R5bGU9InN0b3AtY29sb3I6IzQxNThEMDtzdG9wLW9wYWNpdHk6MSIgLz4KICAgICAgICAgICAgICAgIDxzdG9wIG9mZnNldD0iNTAlIiBzdHlsZT0ic3RvcC1jb2xvcjojQzg1MEMwO3N0b3Atb3BhY2l0eToxIiAvPgogICAgICAgICAgICAgICAgPHN0b3Agb2Zmc2V0PSIxMDAlIiBzdHlsZT0ic3RvcC1jb2xvcjojRkZDQzcwO3N0b3Atb3BhY2l0eToxIiAvPgogICAgICAgICAgICA8L2xpbmVhckdyYWRpZW50PgogICAgICAgICAgICA8ZmlsdGVyIGlkPSJzaGFkb3ciPgogICAgICAgICAgICAgICAgPGZlRHJvcFNoYWRvdyBkeD0iMCIgZHk9IjQiIHN0ZERldmlhdGlvbj0iNCIgZmxvb2Qtb3BhY2l0eT0iMC4yNSIgLz4KICAgICAgICAgICAgPC9maWx0ZXI+CiAgICAgICAgPC9kZWZzPgogICAgICAgIDxyZWN0IHdpZHRoPSI4MDAiIGhlaWdodD0iMjAwIiBmaWxsPSJ1cmwoI2JnLWdyYWRpZW50KSIgcng9IjE1IiByeT0iMTUiLz4KICAgICAgICA8dGV4dCB4PSI0MDAiIHk9IjEwMCIgZm9udC1mYW1pbHk9IkFyaWFsLCBzYW5zLXNlcmlmIiBmb250LXNpemU9IjQ4IgogICAgICAgIGZvbnQtd2VpZ2h0PSJib2xkIiB0ZXh0LWFuY2hvcj0ibWlkZGxlIiBkb21pbmFudC1iYXNlbGluZT0ibWlkZGxlIgogICAgICAgIGZpbGw9IiNGRkZGRkYiIGZpbHRlcj0idXJsKCNzaGFkb3cpIj5EU1grKzwvdGV4dD4KICAgIDwvc3ZnPg==" alt="dsx++-banner" width="800">
</p>
<p align="center">
	<em>❯
DSX++ is a C++ Port of the popular DualSenseX (DSX) API that lets you interract
with the DSX app and tweak advanced features of your DualSense
controller, i.e., Adaptive Triggers and Haptic Feedback on PC!
    </em>
</p>
<p align="center">
	<!-- local repository, no metadata badges. --></p>
<p align="center">Built with the tools and technologies:</p>
<p align="center">
	<img src="https://img.shields.io/badge/-CMake-darkslateblue?logo=cmake" "alt"="C++">
    <img src="https://img.shields.io/badge/-C++-magenta?logo=cplusplus" "alt"="C++">
</p>
<br>

##  Table of Contents

- [ Overview](#overview)
- [ Features](#features)
- [ Getting Started](#getting-started)
  - [ Prerequisites](#prerequisites)
  - [ Installation](#installation)
  - [ Usage](#usage)
  - [ Testing](#testing)
- [ Project Roadmap](#project-roadmap)
- [ Contributing](#contributing)
- [ License](#license)
- [ Acknowledgments](#acknowledgments)

---

##  Overview


[DSX]: https://store.steampowered.com/app/1812620/DSX/
[DualSenseX]: https://github.com/Paliverse/DualSenseX
[DSX Github]: https://github.com/Paliverse/DSX
[DSX Mod System]: https://github.com/Paliverse/DSX/tree/main/Mod%20System%20(DSX%20v3)#dsx-mod-system

DSX++ is a C++ framework that lets you interact with the [DSX] app and alter
your DualSense controller advanced features on the fly. It is mostly meant to
be used by Game Developers or modders that want to bump up the immersion of
their games.

This framework is a Port of the original DSX framework implemented in C#
language. The official project and framework can be found in the following
links:
* [DualSenseX]
* [DSX Github]


---

##  Features

DSX++ supports all the features implemented by the latest version of DSX Mod
System (DSX v3.1+). It also has support of the Legacy v2 Mod System. Here's a
brief summary of the supported features:
* Tweaking the Adaptive Triggers
* Changing the Lightbar LED
* Changing the Player LED
* Changing the Mic LED
* Legacy Addaptive Triggers functions

For more details of the above features, you can have a look on the official
[DSX Mod System] page or visit the store page of [DSX] on Steam.


---
##  Getting Started

###  Prerequisites


> [!IMPORTANT]
> DSX++ framework interacts with the DSX app, so having the app isntalled is
a requirements in order to use the framework. The app can be purchased on
Steam: **[DSX]**.

*The following can be also installed via the DSX app during setup:*

* Very important and required get ViGEmBus Driver:
    * Download the latest `ViGEmBus` drivers from the [ViGEmBus release page](https://github.com/ViGEm/ViGEmBus/releases/latest).
    * To install, double-click `ViGEmBus_Setup_{version}.exe` and follow the instructions presented.

* HidHide Driver (OPTIONAL):
    * Download the latest `HidHide` drivers from the [HidHide release page](https://github.com/ViGEm/HidHide/releases/latest).
    * To install, double-click `HidHideMSI.msi` and follow the instructions presented.
    * **Make sure you reboot your device**

> [!NOTE]
> You'll also need a DualSense controller :video_game:

Once that's  done, the DualSense Controller should auto connect to the App.

In order to use the API, make sure to switch to either DSX v2:
* steps here...

or DSX v3.1 (BETA at the time of writing)
* steps here...

*DSX v3 is not supported!*

Before getting started with DSX++, ensure your runtime environment meets the following requirements:

- **Programming Language:** CPP
- **Package Manager:** Cmake


###  Installation

Install DSX++ using one of the following methods:

**Build from source:**

1. Clone the DSX++ repository:
```sh
❯ git clone https://github.com/tpetsas/DSXpp.git
```

2. Navigate to the project directory:
```sh
❯ cd DSXpp
```

3. Install the project dependencies:

**Using `cmake`** &nbsp; [<img align="center" src="https://img.shields.io/badge/C++-00599C.svg?style={badge_style}&logo=c%2B%2B&logoColor=white" />](https://isocpp.org/)

```sh
❯ mkdir build && cd build
❯ cmake .. && cmake --build .
```

**Download the latest release:**

... text here ...



###  Usage

**Addaptive Triggers CLI Testing app:**

Run DSX++ using the following command:

```sh
❯ ./DSX++
```

**Getting started with sample code:**


---
##  Project Roadmap

[comment]: <> (- [X] **`Task 1`**: <strike>Implement feature one.</strike>)
- [ ] **`Task 1`** Add a Wiki page describing the API.

---

##  Contributing

- **💬 [Join the Discussions](https://LOCAL//DSX++/discussions)**: Share your insights, provide feedback, or ask questions.
- **🐛 [Report Issues](https://LOCAL//DSX++/issues)**: Submit bugs found or log feature requests for the `DSX++` project.
- **💡 [Submit Pull Requests](https://LOCAL//DSX++/blob/main/CONTRIBUTING.md)**: Review open PRs, and submit your own PRs.

<details closed>
<summary>Contributing Guidelines</summary>

1. **Fork the Repository**: Start by forking the project repository to your LOCAL account.
2. **Clone Locally**: Clone the forked repository to your local machine using a git client.
   ```sh
   git clone .\DSX++\
   ```
3. **Create a New Branch**: Always work on a new branch, giving it a descriptive name.
   ```sh
   git checkout -b new-feature-x
   ```
4. **Make Your Changes**: Develop and test your changes locally.
5. **Commit Your Changes**: Commit with a clear message describing your updates.
   ```sh
   git commit -m 'Implemented new feature x.'
   ```
6. **Push to LOCAL**: Push the changes to your forked repository.
   ```sh
   git push origin new-feature-x
   ```
7. **Submit a Pull Request**: Create a PR against the original project repository. Clearly describe the changes and their motivations.
8. **Review**: Once your PR is reviewed and approved, it will be merged into the main branch. Congratulations on your contribution!
</details>

<details closed>
<summary>Contributor Graph</summary>
<br>
<p align="left">
   <a href="https://LOCAL{//DSX++/}graphs/contributors">
      <img src="https://contrib.rocks/image?repo=/DSX++">
   </a>
</p>
</details>

---

##  License

This project is protected under the [MIT License](https://opensource.org/license/mit), refer to the [LICENSE](XXX add file here) file.

---

##  Acknowledgments

- List any resources, contributors, inspiration, etc. here.

---
