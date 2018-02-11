FROM ubuntu:16.04
MAINTAINER megumish
RUN apt-get update
RUN apt-get install xinetd -y
RUN useradd -m flea_attack
RUN chmod 774 /tmp
RUN chmod -R 774 /var/tmp
RUN chmod -R 774 /dev
RUN chmod -R 774 /run
RUN chmod 1733 /tmp /var/tmp /dev/shm
ADD flea_attack /home/flea_attack/
ADD flag /home/flea_attack/
ADD xinetd.conf /etc/xinetd.d/flea_attack
RUN chmod 644 /home/flea_attack/flag
RUN chmod 755 /home/flea_attack/flea_attack
RUN chmod 644 /etc/xinetd.d/flea_attack
RUN chown -R root:root /home/flea_attack

EXPOSE 4869

CMD ["/usr/sbin/xinetd","-dontfork"]
