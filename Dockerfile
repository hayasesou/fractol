FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    gcc \
    make \
    wget \
    bash \
    libx11-dev \
    libxrender-dev \
    libxi-dev \
    libgl1-mesa-dev \
    libbsd-dev \
    libxext-dev \
    xorg \
    x11-apps \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . .

RUN wget https://cdn.intra.42.fr/document/document/27135/minilibx-linux.tgz \
    && tar -xzf minilibx-linux.tgz 

RUN chmod 1777 /tmp
RUN chmod -R 755 /app/minilibx-linux

ENV DISPLAY=:0

CMD ["/bin/bash"]