FROM ubuntu:18.04

COPY ./middle-square-method /home/square/

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y xinetd
RUN apt-get install -y libsodium-dev

RUN groupadd square
RUN useradd -g square square
WORKDIR /home/square

COPY ./square /etc/xinetd.d/

RUN chmod 460 /home/square/*
RUN chown square:root /home/square/*
RUN chmod +x-w /home/square/middle-square-method
RUN chmod o-rx *

RUN echo "square 8801/tcp" >> /etc/services

CMD ["/usr/sbin/xinetd","-dontfork"]
