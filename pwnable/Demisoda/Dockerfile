FROM ubuntu:18.04

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y xinetd


RUN groupadd demisoda
RUN useradd -g demisoda demisoda
WORKDIR /home/demisoda

COPY ./main /home/demisoda/
COPY ./flag /home/demisoda/
COPY ./demisoda /etc/xinetd.d/

RUN chmod 460 /home/demisoda/*
RUN chown demisoda:root /home/demisoda/*
RUN chmod +x-w /home/demisoda/main
RUN chmod o-rx *

RUN echo "demisoda 8813/tcp" >> /etc/services

CMD ["/usr/sbin/xinetd","-dontfork"]
