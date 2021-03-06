//  (C) Copyright 2009-2011 Frederic Bron.
//
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef BOOST_TT_HAS_PRE_INCREMENT_HPP_INCLUDED
#define BOOST_TT_HAS_PRE_INCREMENT_HPP_INCLUDED

#include <boost/type_traits/is_array.hpp>

#define BOOST_TT_TRAIT_NAME has_pre_increment
#define BOOST_TT_TRAIT_OP ++
#define BOOST_TT_FORBIDDEN_IF\
   (\
      /* bool */\
      ::lslboost::is_same< bool, Rhs_nocv >::value || \
      /* void* */\
      (\
         ::lslboost::is_pointer< Rhs_noref >::value && \
         ::lslboost::is_void< Rhs_noptr >::value\
      ) || \
      /* (fundamental or pointer) and const */\
      (\
         ( \
            ::lslboost::is_fundamental< Rhs_nocv >::value || \
            ::lslboost::is_pointer< Rhs_noref >::value\
         ) && \
         ::lslboost::is_const< Rhs_noref >::value\
      )||\
      /* Arrays */ \
      ::lslboost::is_array<Rhs_noref>::value\
      )


#include <boost/type_traits/detail/has_prefix_operator.hpp>

#undef BOOST_TT_TRAIT_NAME
#undef BOOST_TT_TRAIT_OP
#undef BOOST_TT_FORBIDDEN_IF

#endif
