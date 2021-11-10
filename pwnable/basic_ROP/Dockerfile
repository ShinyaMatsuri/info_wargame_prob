FROM ubuntu:16.04

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y xinetd

RUN groupadd basic_rop
RUN useradd -g basic_rop basic_rop
WORKDIR /home/basic_rop

COPY ./main /home/basic_rop/
COPY ./flag /home/basic_rop/
COPY ./basic_rop /etc/xinetd.d/

RUN chmod 460 /home/basic_rop/*
RUN chown basic_rop:root /home/basic_rop/*
RUN chmod +x-w /home/basic_rop/main
RUN chmod o-rx *

RUN echo "basic_rop 8811/tcp" >> /etc/services

CMD ["/usr/sbin/xinetd","-dontfork"]
