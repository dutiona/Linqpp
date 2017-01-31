#pragma once

#pragma warning( push )
#pragma warning( disable : 4268 ) // static/global data initialized with compiler generated default constructor fills the object with zeros
#pragma warning( disable : 4100 ) // unreferenced formal parameter
#pragma warning( disable : 4244 ) // conversion from '__int64' to 'int', possible loss of data
#include <range/v3/all.hpp>
#pragma warning( pop )

#include <iostream>
#include <vector>
#include <tuple>

using namespace ranges;

std::vector<std::tuple<int, int, int>> select() {
   auto triples =
      view::for_each(view::ints(1), [](int z)
   {
      return view::for_each(view::ints(1, z + 1), [=](int x)
      {
         return view::for_each(view::ints(x, z + 1), [=](int y)
         {
            return yield_if(x*x + y*y == z*z, std::make_tuple(x, y, z));
         });
      });
   });

   //// This alternate syntax also works:
   //auto triples = ints(1)      >>= [] (int z) { return
   //               ints(1, z+1) >>= [=](int x) { return
   //               ints(x, z+1) >>= [=](int y) { return
   //    yield_if(x*x + y*y == z*z,
   //        std::make_tuple(x, y, z)); };}; };

   // Display the first 100 triples
   std::vector<std::tuple<int, int, int>> v;
   RANGES_FOR(auto triple, triples | view::take(100))
   {
      v.emplace_back(std::get<0>(triple), std::get<1>(triple), std::get<2>(triple));
   }
   return v;
}