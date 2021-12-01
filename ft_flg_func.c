#include "ft_printf_bonus.h"

void ft_bzero_flg(flg_stc *flg)
{
      flg->flg_mns = '0';
      flg->flg_pls = '0';
      flg->flg_okt = '0';
      flg->flg_spc = '0';
      flg->flg_zro = '0';
      flg->width = 0;
      flg->press = '0';
      flg->type = '0';
}
