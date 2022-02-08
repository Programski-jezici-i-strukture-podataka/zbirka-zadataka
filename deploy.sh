#!/bin/bash

mkdir -p ./docs
touch ./docs/.nojekyll
cp -a _build/html/. ./docs

