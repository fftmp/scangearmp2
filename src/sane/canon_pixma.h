#ifndef __CANON_PIXMA_H__
#define __CANON_PIXMA_H__

#ifndef BACKEND_NAME
#define BACKEND_NAME canon_pixma
#endif

enum canon_sane_Option
{
	OPT_NUM_OPTS = 0,
	OPT_MODE,
	OPT_RESOLUTION,
	OPT_PREVIEW,

	OPT_GEOMETRY_GROUP,
	OPT_TL_X,
	OPT_TL_Y,
	OPT_BR_X,
	OPT_BR_Y,
	/* must come last: */
	NUM_OPTIONS
};

#endif // __CANON_PIXMA_H__
