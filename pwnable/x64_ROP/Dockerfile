FROM ubuntu:18.04

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y xinetd


RUN groupadd x64_rop
RUN useradd -g x64_rop x64_rop
WORKDIR /home/x64_rop

COPY ./main /home/x64_rop/
COPY ./flag /home/x64_rop/
COPY ./x64_rop /etc/xinetd.d/

RUN chmod 460 /home/x64_rop/*
RUN chown x64_rop:root /home/x64_rop/*
RUN chmod +x-w /home/x64_rop/main
RUN chmod o-rx *

RUN echo "x64_rop 8812/tcp" >> /etc/services

CMD ["/usr/sbin/xinetd","-dontfork"]
