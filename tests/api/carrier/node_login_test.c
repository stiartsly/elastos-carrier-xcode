#include <stdlib.h>
#include <unistd.h>
#include <CUnit/Basic.h>

#include "ela_carrier.h"
#include "cond.h"
#include "tests.h"
#include "test_helper.h"

static inline void wakeup(void* context)
{
    cond_signal(((CarrierContext *)context)->cond);
}

static void ready_cb(ElaCarrier *w, void *context)
{
    wakeup(context);
}

static ElaCallbacks callbacks = {
    .idle            = NULL,
    .connection_status = NULL,
    .ready           = ready_cb,
    .self_info       = NULL,
    .friend_list     = NULL,
    .friend_connection = NULL,
    .friend_info     = NULL,
    .friend_presence = NULL,
    .friend_request  = NULL,
    .friend_added    = NULL,
    .friend_removed  = NULL,
    .friend_message  = NULL,
    .friend_invite   = NULL
};

static Condition DEFINE_COND(cond);

static CarrierContext carrier_context = {
    .cbs = &callbacks,
    .carrier = NULL,
    .cond = &cond,
    .extra = NULL
};

static TestContext test_context = {
    .carrier = &carrier_context,
    .session = NULL,
    .stream  = NULL
};

static void test_node_login(void)
{
    ElaCarrier *w = test_context.carrier->carrier;
    char userid[ELA_MAX_ID_LEN + 1];
    char nodeid[ELA_MAX_ID_LEN + 1];
    char login[ELA_MAX_ID_LEN + 1];
    char *p, *q, *r;

    p = ela_get_userid(w, userid, sizeof(userid));
    CU_ASSERT_PTR_NOT_NULL_FATAL(p);

    q = ela_get_nodeid(w, nodeid, sizeof(nodeid));
    CU_ASSERT_PTR_NOT_NULL_FATAL(q);

    r = ela_get_login(w, login, sizeof(login));
    CU_ASSERT_PTR_NOT_NULL_FATAL(r);

    CU_ASSERT_STRING_EQUAL(p, q);
    CU_ASSERT_STRING_EQUAL(p, r);
}

static CU_TestInfo cases[] = {
    { "test_node_login", test_node_login },
    { NULL, NULL }
};

CU_TestInfo *node_login_test_get_cases(void)
{
    return cases;
}

int node_login_test_suite_init(void)
{
    int rc;
    char path[128] = {0};

    snprintf(path, 128, "%s/.carrier.pref", global_config.tests.data_location);
    unlink(path);

    rc = test_suite_init_ext(&test_context, true);
    if (rc < 0)
        CU_FAIL("Error: test suite initialize error");

    return rc;
}

int node_login_test_suite_cleanup(void)
{
    char path[128] = {0};

    test_suite_cleanup(&test_context);

    snprintf(path, 128, "%s/.carrier.pref", global_config.tests.data_location);
    unlink(path);

    return 0;
}
