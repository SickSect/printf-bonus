#include "ft_printf_bonus.h"

void	ft_str_mns(char *str, flg_stc *flg, int f_null)
{
	if (flg->press == -1)
	{
		ft_putstr(str, ft_strlen(str), flg);
		ft_filler(' ', flg->width - ft_strlen(str), flg);
	}
	else
	{
		if (flg->press < ft_strlen(str))
		{
			if (f_null != 1)
				ft_putstr(str, flg->press, flg);
			else if (f_null == 1 && flg->press > 6)
			{
				ft_filler(' ', flg->width, flg);
				ft_putstr("(null)", 6, flg);
			}
			else if (f_null == 1 && flg->press < 6)
				ft_filler(' ', flg->width, flg);
			ft_filler(' ', flg->width - flg->press, flg);
		}
		else
		{
			ft_putstr(str, ft_strlen(str), flg);
			ft_filler(' ', flg->width - ft_strlen(str), flg);
		}
	}
}

void	ft_str_base(char *str, flg_stc *flg, int f_null)
{
	if (flg->press == -1)
	{
		ft_filler(' ', flg->width - ft_strlen(str), flg);
		ft_putstr(str, ft_strlen(str), flg);
	}
	else
	{
		if(flg->press < ft_strlen(str))
		{
			if(f_null == 1 && flg->press < ft_strlen(str))
				return ;
      ft_filler(' ', flg->width - flg->press, flg);
      ft_putstr(str, flg->press, flg);
    }
    else
    {
      ft_filler(' ', flg->width - ft_strlen(str), flg);
      ft_putstr(str, ft_strlen(str), flg);
    }
  }
}

int ft_string(char *str, flg_stc *flg)
{
  int f_null;
  char c_null [] = "(null)";

  f_null = 0;
  if(!str)
  {
    f_null = 1;
    if(flg->mns == 1)
        ft_str_mns(c_null, flg, f_null);
    else
        ft_str_base(c_null, flg, f_null);
    return(0);
  }
    if(flg->mns == 1)
        ft_str_mns(str, flg, f_null);
    else
        ft_str_base(str, flg, f_null);
    return(0);
}
