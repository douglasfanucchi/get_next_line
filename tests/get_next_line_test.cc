#include <gtest/gtest.h>

extern "C" {
	#include <fcntl.h>
	#include <get_next_line.h>
}

TEST(GetNextLine, itShouldReadLineFromAFileDescriptor) {
	int fd[2];
	pipe2(fd, O_NONBLOCK);
	write(fd[1], "hello world!\n", 13);

	char *result = get_next_line(fd[0]);

	ASSERT_STREQ("hello world!\n", result);

	free(result);
	close(fd[0]);
	close(fd[1]);
}

TEST(GetNextLine, itShouldReturnCharactersUntilTheFirstBreaklineChar) {
	int fd[2];
	pipe2(fd, O_NONBLOCK);
	write(fd[1], "hello\nworld\n", 12);

	char *result = get_next_line(fd[0]);

	ASSERT_STREQ("hello\n", result);

	free(result);
	close(fd[0]);
	close(fd[1]);
}

TEST(GetNextLine, itShouldReturnCharactersFromTheSecondLineOnSecondCall) {
	int fd[2];
	pipe2(fd, O_NONBLOCK);
	write(fd[1], "hello\nworld\n", 12);
	free(get_next_line(fd[0]));

	char *result = get_next_line(fd[0]);

	ASSERT_STREQ("world\n", result);

	free(result);
	close(fd[0]);
	close(fd[1]);
}
