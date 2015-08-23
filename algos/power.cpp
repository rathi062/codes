LL power(LL base, int pwr){
    if(pwr==0)
        return 1;
    if(pwr==1)
        return base;
    LL result, ret;
    if(pwr%2){
        result = base;
        ret = power(base, pwr/2);
    }
    else{
        result = 1;
        ret = power(base, pwr/2);
    }
    result = result*ret*ret;
    return result;
}

LL powerWithMod(LL base, int pwr, LL mod){
    if(pwr==0)
        return 1;
    if(pwr==1)
        return base;
    LL result, ret;
    if(pwr%2){
        result = base;
        ret = powerWithMod(base, pwr/2, mod);
    }
    else{
        result = 1;
        ret = powerWithMod(base, pwr/2, mod);
    }
    result = result*ret;
    if(result >= mod) result = result % mod;
    result = result*ret;
    if(result >= mod) result = result % mod;
    return result;
}
