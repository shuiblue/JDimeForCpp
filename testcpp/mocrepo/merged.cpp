#if defined (upstream_fork1_fork1commit1) && (defined (upstream_fork1) && (defined (upstream) || defined (fork1)) || defined (fork1_commit1)) || defined (fork1_commit2)
    void foo();
#endif
#if defined (upstream_fork1_fork1commit1) && (defined (upstream_fork1) && defined (fork1) || defined (fork1_commit1))
    void bar();
#endif
#if defined (upstream_fork1_fork1commit1) && defined (fork1_commit1) || defined (fork1_commit2)
    void fb();
#endif
