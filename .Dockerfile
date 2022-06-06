FROM gcc:latest
RUN apt update
RUN apt install cmake --assume-yes
COPY . /spelly
WORKDIR /spelly
RUN cmake .
RUN make
CMD ./spelly_tests
