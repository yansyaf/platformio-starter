#!/bin/bash

# Get latest short git commit hash
COMMIT_HASH=$(git rev-parse --short HEAD)

# Path to config.h (adjust if needed)
CONFIG_FILE="../include/version.h"

# Replace the FIRMWARE_VERSION define line with the current commit hash
sed -i.bak "s|#define FIRMWARE_VERSION .*|#define FIRMWARE_VERSION \"$COMMIT_HASH\"|" "$CONFIG_FILE"
