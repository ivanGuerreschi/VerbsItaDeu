AM_CFLAGS = -I $(top_srcdir)/src/bin -I $(top_srcdir)/src/lib -Wall -Werror

bin_PROGRAMS = verbsitadeu
verbsitadeu_SOURCES = main.c

verbsitadeu_LDADD = $(top_builddir)/src/lib/libverbs.a $(AM_LDFLAGS)
