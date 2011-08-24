#!/bin/sh

for protocol in 0.9 1.0; do
 for xml in message_definitions/v$protocol/*.xml; do
     ./mavgen.py --lang=C --wire-protocol=$protocol --output=C/include_v$protocol $xml
 done
done

# for mavlink.py just generate for APM for now
./mavgen.py --lang=python --wire-protocol=0.9 --output=../mavlink.py message_definitions/v0.9/ardupilotmega.xml
./mavgen.py --lang=python --wire-protocol=1.0 --output=../mavlinkv10.py message_definitions/v1.0/ardupilotmega.xml
