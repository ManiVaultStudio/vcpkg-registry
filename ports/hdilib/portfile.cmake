set(VCPKG_BUILD_TYPE release)  # pre-built, no debug variant
vcpkg_from_github(
  OUT_SOURCE_PATH SOURCE_PATH
  REPO "biovault/HDILib"
  REF "v${VERSION}" 
  SHA512 "e9f07afbaa68c3f31169af62db983e023ba38f3ddbe32664f2adfbe1ebd4c1cf04ac33d2d104ecfe12ccbb48fdaf323eb347f43d03ff85abbd4690bb7c5902d2"
)

vcpkg_cmake_configure( SOURCE_PATH "${SOURCE_PATH}"
  OPTIONS "-DCMAKE_BUILD_TYPE=Release")

vcpkg_cmake_install()

  # Handle copyright
file(INSTALL "${SOURCE_PATH}/LICENSE" DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}" RENAME "copyright")