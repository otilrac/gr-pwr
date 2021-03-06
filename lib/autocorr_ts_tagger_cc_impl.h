/* -*- c++ -*- */
/* 
 * Copyright 2017 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_PWR_AUTOCORR_TS_TAGGER_CC_IMPL_H
#define INCLUDED_PWR_AUTOCORR_TS_TAGGER_CC_IMPL_H

#include <pwr/autocorr_ts_tagger_cc.h>

namespace gr {
  namespace pwr {

    class autocorr_ts_tagger_cc_impl : public autocorr_ts_tagger_cc
    {
     private:
      int d_auto_cnt;
      const int d_gap_len;
      const int d_valid_len;
      const pmt::pmt_t d_auto_key;
      const pmt::pmt_t d_this_block;
      float d_threshold;
      int d_delay;
      long int d_gap_cnt;

     public:
      autocorr_ts_tagger_cc_impl(float threshold, int delay);
      ~autocorr_ts_tagger_cc_impl();

      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
    };

  } // namespace pwr
} // namespace gr

#endif /* INCLUDED_PWR_AUTOCORR_TS_TAGGER_CC_IMPL_H */

