Debian packaging for sysrepo
============================

This repository contains Debian package files for
[sysrepo](https://github.com/sysrepo/sysrepo).

Building a release with Debian patches
--------------------------------------

```
git clone https://github.com/opensourcerouting/libyang-debian.git
cd libyang-debian
dpkg-buildpackage -uc -us
```

Skip the tests
--------------

```
export DEB_BUILD_OPTIONS="nocheck"
```

