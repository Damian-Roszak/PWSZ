do
    {
        suma=suma+suma*oprocentowanie_roczne*0.01/(12/okres_kapitalizacji);
        cout<<suma<<endl;
        licznik++;
    }while(suma<oczekiwane_odsetki+kwota_poczatkowa);
    
    
    auto okresy(float o, float k_w, float o_r, float m_kap) {
    int okresy=0;
    float pomocniczy, kap = 0;
    pomocniczy = k_w + o;
    kap = (o_r / (12 / m_kap) / 100) + 1;
    while (k_w < pomocniczy) {
        k_w*= kap;
        okresy++;
}
    return okresy;
}
