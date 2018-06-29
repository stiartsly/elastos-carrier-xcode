Xcode Workspace for Elastos Carrier SDK
=====================================

## Summary

Here is Apple Xcode workspace for **Elastos.NET.Carrier.Native.SDK** repository to build/compile/debug in convinience way.

## How to be invovled.

Run following commands to get xcode involved on MacOS:

```shell
$ git clone https://github.com/elastos/Elastos.NET.Carrier.Native.SDK.git
$ cd Elastos.NET.Carrier.Native.SDK
$ git clone https://github.com/stiartsly/elastos-carrier-xcode.git xcode
$ cd xcode
$ open -a Xcode.app elastos.xcworkspace
```
Therefore, you can use Apple Xcode to edit/compile/debug Elastos Carrier on MacOS.


## Issues

When you compile toxcore target, If you come across problems, just delete all intermediates for toxcore.

```shell
$ cd Elastos.NET.Carrier.Native.SDK/build/_build/Xcode/debug
$ rm -rf c-toxcore
```

Then clean toxcore and rebuild it.

## License
MIT
