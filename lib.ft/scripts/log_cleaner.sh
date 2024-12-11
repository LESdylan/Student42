#!/bin/bash
# Log Cleaner

LOG_DIR=${1:-/var/log}
DAYS=${2:-30}

find "$LOG_DIR" -type f -mtime +"$DAYS" -exec rm -f {} \;
echo "Logs older than $DAYS days have been cleaned from $LOG_DIR."
