FROM gcc:latest
RUN apt update
RUN apt install cmake --assume-yes
RUN apt-get install doxygen
COPY . /spelly
WORKDIR /spelly
RUN doxygen .doxygen
RUN cmake .
RUN make
CMD ./spelly
