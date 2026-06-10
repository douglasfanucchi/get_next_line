#include <gtest/gtest.h>

extern "C" {
	#include <get_next_line.h>
}

TEST(Buffer, itShouldInitializeBufferWithSpecificFileDescriptor) {
	t_buffer buffer;
	int fd = 0;
	initialize_buffer(&buffer, fd);

	ASSERT_TRUE(buffer.is_empty(buffer));
}
