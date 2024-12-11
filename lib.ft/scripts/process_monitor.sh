#!/bin/bash
# Process Monitor

PROCESS="nginx"

if ! pgrep -x "$PROCESS" > /dev/null; then
  echo "$PROCESS is not running. Restarting..."
  sudo systemctl start "$PROCESS"
else
  echo "$PROCESS is running."
fi
