#ifdef __cpluscplus
extern "C" {
#endif

int GridToWgs84(int x, int y, float* lon, float* lat);
int Wgs84ToGrid(float lon, float lat, int* x, int* y);

#ifdef __cpluscplus
}
#endif
