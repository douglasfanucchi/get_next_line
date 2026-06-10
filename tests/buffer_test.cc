#include <gtest/gtest.h>

extern "C" {
	#include <get_next_line.h>
	#include <fcntl.h>
	#include <math.h>
}

TEST(Buffer, itShouldInitializeBufferWithSpecificFileDescriptor) {
	t_buffer buffer;
	int fd = 0;
	initialize_buffer(&buffer, fd);

	ASSERT_TRUE(buffer.is_empty(buffer));
}

TEST(Buffer, itShouldFillBufferWithBytesFromSpecifiedFdAndFreeIt) {
	t_buffer buffer;
	int fd[2];
	int expected = fmin(11, BUFFER_SIZE);
	pipe2(fd, O_NONBLOCK);
	write(fd[1], "hello world", 11);
	initialize_buffer(&buffer, fd[0]);

	int result = buffer.fill(&buffer);
	ASSERT_EQ(expected, result);
	ASSERT_FALSE(buffer.is_empty(buffer));

	buffer.free(&buffer);
	ASSERT_TRUE(buffer.is_empty(buffer));

	close(fd[0]);
	close(fd[1]);
}

TEST(Buffer, itShouldGetNextCharFromBuffer) {
	t_buffer buffer;
	int fd[2];
	pipe2(fd, O_NONBLOCK);
	write(fd[1], "hello world", 11);
	initialize_buffer(&buffer, fd[0]);
	buffer.fill(&buffer);

	ASSERT_EQ('h', buffer.get_next_char(&buffer));

	close(fd[0]);
	close(fd[1]);
	buffer.free(&buffer);
}
