#include <gtest/gtest.h>

extern "C" {
	#include <get_next_line.h>
}

TEST(FTlsttostr, itShouldConvertAnEmptyListToEmptyString) {
	t_list	*node = NULL;

	char *result = ft_lsttostr(node);

	ASSERT_STREQ("", result);

	free(result);
}
