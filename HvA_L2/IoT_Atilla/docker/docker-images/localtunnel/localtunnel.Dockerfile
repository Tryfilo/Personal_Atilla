###############################################################################################################################
# This Dockerfile constructs a lightweight linux environment where a connection will be setup to Localtunnel
# Source: https://github.com/localtunnel/localtunnel
# 
# Author: Mats Otten
# Date: 28 februari 2023
###############################################################################################################################

FROM mhart/alpine-node

RUN apk add --no-cache --update php

# Install node package of Localtunnel
RUN npm install -g localtunnel

# Copy run-script to docker environment
ADD localtunnel.sh /

# Makes run-script runnable
RUN chmod +x /localtunnel.sh

# Run the script
CMD sh /localtunnel.sh ${TUNNEL_SUBDOMAIN}
