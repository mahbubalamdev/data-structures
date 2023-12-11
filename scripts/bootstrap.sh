#!/bin/bash

export DEBIAN_FRONTEND=noninteractive
sudo apt-get update
sudo apt install software-properties-common -y
sudo apt-get install build-essential -y
sudo apt-get install libc6-dev linux-libc-dev linux-headers-$(uname -r)
sudo add-apt-repository ppa:deadsnakes/ppa -y

sudo apt-get install -y python3.10 python3.10-dev python3.10-venv
sudo ln -s /usr/bin/python3.10 /usr/bin/python
