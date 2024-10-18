#!/bin/bash

curl -fL https://getcli.jfrog.io | sh

export PATH_PREFIX=luxonis-zoo/depthai

./jfrog config add --artifactory-url=$ARTIFACTORY_URL --user=$ARTIFACTORY_USER --password=$ARTIFACTORY_PASS
./jfrog rt u "build_core/zoo_helper" "$PATH_PREFIX/"
