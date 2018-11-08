
int part2(int *score, int *retreat);

void background(int *gpoint, int *fpoint);

void move_goku(int s, int *m, int *gpoint, int *fpoint);

void blast_move(int *gblastx, int blast_dir, int *x, int *shoot_flag, int *t, int *n, int *gpoint, int *fpoint);

void goku_jump(int *h, int *r, int i, int s, int *m, int *gblastx, int blast_dir, int *x, int *shoot_flag, int *t, int *n, int *gpoint, int *fpoint, int *fshoot_flag, int *fblast_dir, int *fblastx, int *y);

void goku_shoot(int s, int m, int *blast_dir, int *gblastx, int *gpoint, int *fpoint);

void goku_punch(int *r, int i, int *t, int *n, int *s, int *m, int *gpoint, int *fpoint, int *fshoot_flag, int *fblast_dir, int *fblastx, int *y);

void move_frieza(int *r, int i, int *t, int *n, int s, int *m, int *gpoint, int *fpoint, int *fshoot_flag, int *fblast_dir, int *fblastx, int *y);

void fblast_move(int *h, int *fblastx, int fblast_dir, int *y, int *fshoot_flag, int *t, int *m, int *gpoint, int *fpoint);
