# Set the source files that make up the library
set(FIFO_SRCS
   fifo.h fifo.c
)

# Set the library type (can be static or dynamic )
set(LIB_TYPE STATIC)

# Create the library
add_library(FIFOLib ${LIB_TYPE} ${FIFO_SRCS})