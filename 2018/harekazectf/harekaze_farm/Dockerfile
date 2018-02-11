FROM ubuntu:16.04
MAINTAINER megumish
RUN apt-get update && apt-get install -y xinetd \
    && useradd -m harekaze_farm \
    && chown -R root:root /home/harekaze_farm

ADD harekaze_farm /home/harekaze_farm/
ADD flag /home/harekaze_farm/
ADD xinetd.conf /etc/xinetd.d/harekaze_farm

RUN chmod 644 /home/harekaze_farm/flag \
    && chmod 755 /home/harekaze_farm/harekaze_farm \
    && chmod 644 /etc/xinetd.d/harekaze_farm

EXPOSE 23942

CMD ["/usr/sbin/xinetd", "-dontfork"]
