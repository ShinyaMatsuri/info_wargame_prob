FROM ubuntu:18.04

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y xinetd


RUN groupadd lemon
RUN useradd -g lemon lemon
WORKDIR /home/lemon

COPY ./main /home/lemon/
COPY ./flag /home/lemon/
COPY ./lemon /etc/xinetd.d/

RUN chmod 460 /home/lemon/*
RUN chown lemon:root /home/lemon/*
RUN chmod +x-w /home/lemon/main
RUN chmod o-rx *

RUN echo "lemon 8810/tcp" >> /etc/services

CMD ["/usr/sbin/xinetd","-dontfork"]
