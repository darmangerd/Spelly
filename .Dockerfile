FROM gcc:latest
RUN apt update
RUN apt install cmake --assume-yes
COPY . /spelly
WORKDIR /spelly
RUN ls
RUN cmake .
RUN make
CMD ./spelly
