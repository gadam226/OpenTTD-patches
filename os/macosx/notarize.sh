#!/bin/bash
set -e

# This script attempts to notarize the OpenTTD DMG generated by CPack.
# If you are building an unofficial branch of OpenTTD, please change the bundle
# ID in Info.plist and below.
#
# This uses `gon' to perform notarization:
#
#   https://github.com/mitchellh/gon
#
# Follow the setup instructions on the gon site to install.
#
# Before executing this script, you must first configure CMake with at least the following
# parameters:
#
# -DCPACK_BUNDLE_APPLE_CERT_APP={certificate ID}
# "-DCPACK_BUNDLE_APPLE_CODESIGN_PARAMETER=--deep -f --options runtime"
#
# then run "make package" or "cpack".
#
# This will sign the application with your signing certificate, and will enable
# the hardened runtime.
#
# You also need to set your Apple Developer username and password (app-specific password
# is recommended) in the AC_USERNAME and AC_PASSWORD environment variables.
#
# Then, ensuring you're in your build directory and that the "bundles" directory
# exists with a .dmg in it (clear out any old DMGs first), run:
#
# ../os/macosx/notarize.sh

if [ -z "${AC_USERNAME}" ]; then
    echo AC_USERNAME not set, skipping notarization.
    exit 0
fi;

dmg_filename=(bundles/*.dmg)

if [ "${dmg_filename}" = "bundles/*.dmg" ]; then
    echo "No .dmg found in the bundles directory, skipping notarization. Please read this"
    echo "script's source for execution instructions."
    exit 1
fi;

cat <<EOF > notarize.json
{
   "notarize": [
      {
         "path": "${dmg_filename[0]}",
         "bundle_id": "org.openttd.openttd",
         "staple": true
      }
   ]
}
EOF

gon notarize.json
