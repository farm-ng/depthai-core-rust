// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: daischemas/LinePrimitive.proto
// Protobuf C++ Version: 4.25.1

#ifndef GOOGLE_PROTOBUF_INCLUDED_daischemas_2fLinePrimitive_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_daischemas_2fLinePrimitive_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION < 4025000
#error "This file was generated by a newer version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please update"
#error "your headers."
#endif  // PROTOBUF_VERSION

#if 4025001 < PROTOBUF_MIN_PROTOC_VERSION
#error "This file was generated by an older version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please"
#error "regenerate this file with a newer version of protoc."
#endif  // PROTOBUF_MIN_PROTOC_VERSION
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/generated_enum_reflection.h"
#include "google/protobuf/unknown_field_set.h"
#include "daischemas/Color.pb.h"
#include "daischemas/Point3.pb.h"
#include "daischemas/Pose.pb.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_daischemas_2fLinePrimitive_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_daischemas_2fLinePrimitive_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_daischemas_2fLinePrimitive_2eproto;
namespace dai {
namespace schemas {
class LinePrimitive;
struct LinePrimitiveDefaultTypeInternal;
extern LinePrimitiveDefaultTypeInternal _LinePrimitive_default_instance_;
}  // namespace schemas
}  // namespace dai
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace dai {
namespace schemas {
enum LinePrimitive_Type : int {
  LinePrimitive_Type_LINE_STRIP = 0,
  LinePrimitive_Type_LINE_LOOP = 1,
  LinePrimitive_Type_LINE_LIST = 2,
  LinePrimitive_Type_LinePrimitive_Type_INT_MIN_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::min(),
  LinePrimitive_Type_LinePrimitive_Type_INT_MAX_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::max(),
};

bool LinePrimitive_Type_IsValid(int value);
extern const uint32_t LinePrimitive_Type_internal_data_[];
constexpr LinePrimitive_Type LinePrimitive_Type_Type_MIN = static_cast<LinePrimitive_Type>(0);
constexpr LinePrimitive_Type LinePrimitive_Type_Type_MAX = static_cast<LinePrimitive_Type>(2);
constexpr int LinePrimitive_Type_Type_ARRAYSIZE = 2 + 1;
const ::google::protobuf::EnumDescriptor*
LinePrimitive_Type_descriptor();
template <typename T>
const std::string& LinePrimitive_Type_Name(T value) {
  static_assert(std::is_same<T, LinePrimitive_Type>::value ||
                    std::is_integral<T>::value,
                "Incorrect type passed to Type_Name().");
  return LinePrimitive_Type_Name(static_cast<LinePrimitive_Type>(value));
}
template <>
inline const std::string& LinePrimitive_Type_Name(LinePrimitive_Type value) {
  return ::google::protobuf::internal::NameOfDenseEnum<LinePrimitive_Type_descriptor,
                                                 0, 2>(
      static_cast<int>(value));
}
inline bool LinePrimitive_Type_Parse(absl::string_view name, LinePrimitive_Type* value) {
  return ::google::protobuf::internal::ParseNamedEnum<LinePrimitive_Type>(
      LinePrimitive_Type_descriptor(), name, value);
}

// ===================================================================


// -------------------------------------------------------------------

class LinePrimitive final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:dai.schemas.LinePrimitive) */ {
 public:
  inline LinePrimitive() : LinePrimitive(nullptr) {}
  ~LinePrimitive() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR LinePrimitive(::google::protobuf::internal::ConstantInitialized);

  inline LinePrimitive(const LinePrimitive& from)
      : LinePrimitive(nullptr, from) {}
  LinePrimitive(LinePrimitive&& from) noexcept
    : LinePrimitive() {
    *this = ::std::move(from);
  }

  inline LinePrimitive& operator=(const LinePrimitive& from) {
    CopyFrom(from);
    return *this;
  }
  inline LinePrimitive& operator=(LinePrimitive&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const LinePrimitive& default_instance() {
    return *internal_default_instance();
  }
  static inline const LinePrimitive* internal_default_instance() {
    return reinterpret_cast<const LinePrimitive*>(
               &_LinePrimitive_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(LinePrimitive& a, LinePrimitive& b) {
    a.Swap(&b);
  }
  inline void Swap(LinePrimitive* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr &&
        GetArena() == other->GetArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(LinePrimitive* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  LinePrimitive* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<LinePrimitive>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const LinePrimitive& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const LinePrimitive& from) {
    LinePrimitive::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  ::google::protobuf::internal::CachedSize* AccessCachedSize() const final;
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(LinePrimitive* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "dai.schemas.LinePrimitive";
  }
  protected:
  explicit LinePrimitive(::google::protobuf::Arena* arena);
  LinePrimitive(::google::protobuf::Arena* arena, const LinePrimitive& from);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  using Type = LinePrimitive_Type;
  static constexpr Type LINE_STRIP = LinePrimitive_Type_LINE_STRIP;
  static constexpr Type LINE_LOOP = LinePrimitive_Type_LINE_LOOP;
  static constexpr Type LINE_LIST = LinePrimitive_Type_LINE_LIST;
  static inline bool Type_IsValid(int value) {
    return LinePrimitive_Type_IsValid(value);
  }
  static constexpr Type Type_MIN = LinePrimitive_Type_Type_MIN;
  static constexpr Type Type_MAX = LinePrimitive_Type_Type_MAX;
  static constexpr int Type_ARRAYSIZE = LinePrimitive_Type_Type_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor* Type_descriptor() {
    return LinePrimitive_Type_descriptor();
  }
  template <typename T>
  static inline const std::string& Type_Name(T value) {
    return LinePrimitive_Type_Name(value);
  }
  static inline bool Type_Parse(absl::string_view name, Type* value) {
    return LinePrimitive_Type_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kPointsFieldNumber = 5,
    kColorsFieldNumber = 7,
    kIndicesFieldNumber = 8,
    kPoseFieldNumber = 2,
    kColorFieldNumber = 6,
    kTypeFieldNumber = 1,
    kScaleInvariantFieldNumber = 4,
    kThicknessFieldNumber = 3,
  };
  // repeated .dai.schemas.Point3 points = 5;
  int points_size() const;
  private:
  int _internal_points_size() const;

  public:
  void clear_points() ;
  ::dai::schemas::Point3* mutable_points(int index);
  ::google::protobuf::RepeatedPtrField< ::dai::schemas::Point3 >*
      mutable_points();
  private:
  const ::google::protobuf::RepeatedPtrField<::dai::schemas::Point3>& _internal_points() const;
  ::google::protobuf::RepeatedPtrField<::dai::schemas::Point3>* _internal_mutable_points();
  public:
  const ::dai::schemas::Point3& points(int index) const;
  ::dai::schemas::Point3* add_points();
  const ::google::protobuf::RepeatedPtrField< ::dai::schemas::Point3 >&
      points() const;
  // repeated .dai.schemas.Color colors = 7;
  int colors_size() const;
  private:
  int _internal_colors_size() const;

  public:
  void clear_colors() ;
  ::dai::schemas::Color* mutable_colors(int index);
  ::google::protobuf::RepeatedPtrField< ::dai::schemas::Color >*
      mutable_colors();
  private:
  const ::google::protobuf::RepeatedPtrField<::dai::schemas::Color>& _internal_colors() const;
  ::google::protobuf::RepeatedPtrField<::dai::schemas::Color>* _internal_mutable_colors();
  public:
  const ::dai::schemas::Color& colors(int index) const;
  ::dai::schemas::Color* add_colors();
  const ::google::protobuf::RepeatedPtrField< ::dai::schemas::Color >&
      colors() const;
  // repeated fixed32 indices = 8;
  int indices_size() const;
  private:
  int _internal_indices_size() const;

  public:
  void clear_indices() ;
  ::uint32_t indices(int index) const;
  void set_indices(int index, ::uint32_t value);
  void add_indices(::uint32_t value);
  const ::google::protobuf::RepeatedField<::uint32_t>& indices() const;
  ::google::protobuf::RepeatedField<::uint32_t>* mutable_indices();

  private:
  const ::google::protobuf::RepeatedField<::uint32_t>& _internal_indices() const;
  ::google::protobuf::RepeatedField<::uint32_t>* _internal_mutable_indices();

  public:
  // .dai.schemas.Pose pose = 2;
  bool has_pose() const;
  void clear_pose() ;
  const ::dai::schemas::Pose& pose() const;
  PROTOBUF_NODISCARD ::dai::schemas::Pose* release_pose();
  ::dai::schemas::Pose* mutable_pose();
  void set_allocated_pose(::dai::schemas::Pose* value);
  void unsafe_arena_set_allocated_pose(::dai::schemas::Pose* value);
  ::dai::schemas::Pose* unsafe_arena_release_pose();

  private:
  const ::dai::schemas::Pose& _internal_pose() const;
  ::dai::schemas::Pose* _internal_mutable_pose();

  public:
  // .dai.schemas.Color color = 6;
  bool has_color() const;
  void clear_color() ;
  const ::dai::schemas::Color& color() const;
  PROTOBUF_NODISCARD ::dai::schemas::Color* release_color();
  ::dai::schemas::Color* mutable_color();
  void set_allocated_color(::dai::schemas::Color* value);
  void unsafe_arena_set_allocated_color(::dai::schemas::Color* value);
  ::dai::schemas::Color* unsafe_arena_release_color();

  private:
  const ::dai::schemas::Color& _internal_color() const;
  ::dai::schemas::Color* _internal_mutable_color();

  public:
  // .dai.schemas.LinePrimitive.Type type = 1;
  void clear_type() ;
  ::dai::schemas::LinePrimitive_Type type() const;
  void set_type(::dai::schemas::LinePrimitive_Type value);

  private:
  ::dai::schemas::LinePrimitive_Type _internal_type() const;
  void _internal_set_type(::dai::schemas::LinePrimitive_Type value);

  public:
  // bool scale_invariant = 4;
  void clear_scale_invariant() ;
  bool scale_invariant() const;
  void set_scale_invariant(bool value);

  private:
  bool _internal_scale_invariant() const;
  void _internal_set_scale_invariant(bool value);

  public:
  // double thickness = 3;
  void clear_thickness() ;
  double thickness() const;
  void set_thickness(double value);

  private:
  double _internal_thickness() const;
  void _internal_set_thickness(double value);

  public:
  // @@protoc_insertion_point(class_scope:dai.schemas.LinePrimitive)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      3, 8, 4,
      0, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {

        inline explicit constexpr Impl_(
            ::google::protobuf::internal::ConstantInitialized) noexcept;
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena);
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena, const Impl_& from);
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    ::google::protobuf::RepeatedPtrField< ::dai::schemas::Point3 > points_;
    ::google::protobuf::RepeatedPtrField< ::dai::schemas::Color > colors_;
    ::google::protobuf::RepeatedField<::uint32_t> indices_;
    ::dai::schemas::Pose* pose_;
    ::dai::schemas::Color* color_;
    int type_;
    bool scale_invariant_;
    double thickness_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_daischemas_2fLinePrimitive_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// LinePrimitive

// .dai.schemas.LinePrimitive.Type type = 1;
inline void LinePrimitive::clear_type() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.type_ = 0;
}
inline ::dai::schemas::LinePrimitive_Type LinePrimitive::type() const {
  // @@protoc_insertion_point(field_get:dai.schemas.LinePrimitive.type)
  return _internal_type();
}
inline void LinePrimitive::set_type(::dai::schemas::LinePrimitive_Type value) {
  _internal_set_type(value);
  // @@protoc_insertion_point(field_set:dai.schemas.LinePrimitive.type)
}
inline ::dai::schemas::LinePrimitive_Type LinePrimitive::_internal_type() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return static_cast<::dai::schemas::LinePrimitive_Type>(_impl_.type_);
}
inline void LinePrimitive::_internal_set_type(::dai::schemas::LinePrimitive_Type value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.type_ = value;
}

// .dai.schemas.Pose pose = 2;
inline bool LinePrimitive::has_pose() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.pose_ != nullptr);
  return value;
}
inline const ::dai::schemas::Pose& LinePrimitive::_internal_pose() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  const ::dai::schemas::Pose* p = _impl_.pose_;
  return p != nullptr ? *p : reinterpret_cast<const ::dai::schemas::Pose&>(::dai::schemas::_Pose_default_instance_);
}
inline const ::dai::schemas::Pose& LinePrimitive::pose() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:dai.schemas.LinePrimitive.pose)
  return _internal_pose();
}
inline void LinePrimitive::unsafe_arena_set_allocated_pose(::dai::schemas::Pose* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.pose_);
  }
  _impl_.pose_ = reinterpret_cast<::dai::schemas::Pose*>(value);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:dai.schemas.LinePrimitive.pose)
}
inline ::dai::schemas::Pose* LinePrimitive::release_pose() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);

  _impl_._has_bits_[0] &= ~0x00000001u;
  ::dai::schemas::Pose* released = _impl_.pose_;
  _impl_.pose_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old = reinterpret_cast<::google::protobuf::MessageLite*>(released);
  released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  if (GetArena() == nullptr) {
    delete old;
  }
#else   // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArena() != nullptr) {
    released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return released;
}
inline ::dai::schemas::Pose* LinePrimitive::unsafe_arena_release_pose() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:dai.schemas.LinePrimitive.pose)

  _impl_._has_bits_[0] &= ~0x00000001u;
  ::dai::schemas::Pose* temp = _impl_.pose_;
  _impl_.pose_ = nullptr;
  return temp;
}
inline ::dai::schemas::Pose* LinePrimitive::_internal_mutable_pose() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  if (_impl_.pose_ == nullptr) {
    auto* p = CreateMaybeMessage<::dai::schemas::Pose>(GetArena());
    _impl_.pose_ = reinterpret_cast<::dai::schemas::Pose*>(p);
  }
  return _impl_.pose_;
}
inline ::dai::schemas::Pose* LinePrimitive::mutable_pose() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  ::dai::schemas::Pose* _msg = _internal_mutable_pose();
  // @@protoc_insertion_point(field_mutable:dai.schemas.LinePrimitive.pose)
  return _msg;
}
inline void LinePrimitive::set_allocated_pose(::dai::schemas::Pose* value) {
  ::google::protobuf::Arena* message_arena = GetArena();
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (message_arena == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.pose_);
  }

  if (value != nullptr) {
    ::google::protobuf::Arena* submessage_arena = reinterpret_cast<::google::protobuf::MessageLite*>(value)->GetArena();
    if (message_arena != submessage_arena) {
      value = ::google::protobuf::internal::GetOwnedMessage(message_arena, value, submessage_arena);
    }
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }

  _impl_.pose_ = reinterpret_cast<::dai::schemas::Pose*>(value);
  // @@protoc_insertion_point(field_set_allocated:dai.schemas.LinePrimitive.pose)
}

// double thickness = 3;
inline void LinePrimitive::clear_thickness() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.thickness_ = 0;
}
inline double LinePrimitive::thickness() const {
  // @@protoc_insertion_point(field_get:dai.schemas.LinePrimitive.thickness)
  return _internal_thickness();
}
inline void LinePrimitive::set_thickness(double value) {
  _internal_set_thickness(value);
  // @@protoc_insertion_point(field_set:dai.schemas.LinePrimitive.thickness)
}
inline double LinePrimitive::_internal_thickness() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.thickness_;
}
inline void LinePrimitive::_internal_set_thickness(double value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.thickness_ = value;
}

// bool scale_invariant = 4;
inline void LinePrimitive::clear_scale_invariant() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.scale_invariant_ = false;
}
inline bool LinePrimitive::scale_invariant() const {
  // @@protoc_insertion_point(field_get:dai.schemas.LinePrimitive.scale_invariant)
  return _internal_scale_invariant();
}
inline void LinePrimitive::set_scale_invariant(bool value) {
  _internal_set_scale_invariant(value);
  // @@protoc_insertion_point(field_set:dai.schemas.LinePrimitive.scale_invariant)
}
inline bool LinePrimitive::_internal_scale_invariant() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.scale_invariant_;
}
inline void LinePrimitive::_internal_set_scale_invariant(bool value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.scale_invariant_ = value;
}

// repeated .dai.schemas.Point3 points = 5;
inline int LinePrimitive::_internal_points_size() const {
  return _internal_points().size();
}
inline int LinePrimitive::points_size() const {
  return _internal_points_size();
}
inline ::dai::schemas::Point3* LinePrimitive::mutable_points(int index)
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable:dai.schemas.LinePrimitive.points)
  return _internal_mutable_points()->Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField<::dai::schemas::Point3>* LinePrimitive::mutable_points()
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable_list:dai.schemas.LinePrimitive.points)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  return _internal_mutable_points();
}
inline const ::dai::schemas::Point3& LinePrimitive::points(int index) const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:dai.schemas.LinePrimitive.points)
  return _internal_points().Get(index);
}
inline ::dai::schemas::Point3* LinePrimitive::add_points() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::dai::schemas::Point3* _add = _internal_mutable_points()->Add();
  // @@protoc_insertion_point(field_add:dai.schemas.LinePrimitive.points)
  return _add;
}
inline const ::google::protobuf::RepeatedPtrField<::dai::schemas::Point3>& LinePrimitive::points() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_list:dai.schemas.LinePrimitive.points)
  return _internal_points();
}
inline const ::google::protobuf::RepeatedPtrField<::dai::schemas::Point3>&
LinePrimitive::_internal_points() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.points_;
}
inline ::google::protobuf::RepeatedPtrField<::dai::schemas::Point3>*
LinePrimitive::_internal_mutable_points() {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return &_impl_.points_;
}

// .dai.schemas.Color color = 6;
inline bool LinePrimitive::has_color() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.color_ != nullptr);
  return value;
}
inline const ::dai::schemas::Color& LinePrimitive::_internal_color() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  const ::dai::schemas::Color* p = _impl_.color_;
  return p != nullptr ? *p : reinterpret_cast<const ::dai::schemas::Color&>(::dai::schemas::_Color_default_instance_);
}
inline const ::dai::schemas::Color& LinePrimitive::color() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:dai.schemas.LinePrimitive.color)
  return _internal_color();
}
inline void LinePrimitive::unsafe_arena_set_allocated_color(::dai::schemas::Color* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.color_);
  }
  _impl_.color_ = reinterpret_cast<::dai::schemas::Color*>(value);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:dai.schemas.LinePrimitive.color)
}
inline ::dai::schemas::Color* LinePrimitive::release_color() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);

  _impl_._has_bits_[0] &= ~0x00000002u;
  ::dai::schemas::Color* released = _impl_.color_;
  _impl_.color_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old = reinterpret_cast<::google::protobuf::MessageLite*>(released);
  released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  if (GetArena() == nullptr) {
    delete old;
  }
#else   // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArena() != nullptr) {
    released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return released;
}
inline ::dai::schemas::Color* LinePrimitive::unsafe_arena_release_color() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:dai.schemas.LinePrimitive.color)

  _impl_._has_bits_[0] &= ~0x00000002u;
  ::dai::schemas::Color* temp = _impl_.color_;
  _impl_.color_ = nullptr;
  return temp;
}
inline ::dai::schemas::Color* LinePrimitive::_internal_mutable_color() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000002u;
  if (_impl_.color_ == nullptr) {
    auto* p = CreateMaybeMessage<::dai::schemas::Color>(GetArena());
    _impl_.color_ = reinterpret_cast<::dai::schemas::Color*>(p);
  }
  return _impl_.color_;
}
inline ::dai::schemas::Color* LinePrimitive::mutable_color() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  ::dai::schemas::Color* _msg = _internal_mutable_color();
  // @@protoc_insertion_point(field_mutable:dai.schemas.LinePrimitive.color)
  return _msg;
}
inline void LinePrimitive::set_allocated_color(::dai::schemas::Color* value) {
  ::google::protobuf::Arena* message_arena = GetArena();
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (message_arena == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.color_);
  }

  if (value != nullptr) {
    ::google::protobuf::Arena* submessage_arena = reinterpret_cast<::google::protobuf::MessageLite*>(value)->GetArena();
    if (message_arena != submessage_arena) {
      value = ::google::protobuf::internal::GetOwnedMessage(message_arena, value, submessage_arena);
    }
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }

  _impl_.color_ = reinterpret_cast<::dai::schemas::Color*>(value);
  // @@protoc_insertion_point(field_set_allocated:dai.schemas.LinePrimitive.color)
}

// repeated .dai.schemas.Color colors = 7;
inline int LinePrimitive::_internal_colors_size() const {
  return _internal_colors().size();
}
inline int LinePrimitive::colors_size() const {
  return _internal_colors_size();
}
inline ::dai::schemas::Color* LinePrimitive::mutable_colors(int index)
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable:dai.schemas.LinePrimitive.colors)
  return _internal_mutable_colors()->Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField<::dai::schemas::Color>* LinePrimitive::mutable_colors()
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable_list:dai.schemas.LinePrimitive.colors)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  return _internal_mutable_colors();
}
inline const ::dai::schemas::Color& LinePrimitive::colors(int index) const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:dai.schemas.LinePrimitive.colors)
  return _internal_colors().Get(index);
}
inline ::dai::schemas::Color* LinePrimitive::add_colors() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::dai::schemas::Color* _add = _internal_mutable_colors()->Add();
  // @@protoc_insertion_point(field_add:dai.schemas.LinePrimitive.colors)
  return _add;
}
inline const ::google::protobuf::RepeatedPtrField<::dai::schemas::Color>& LinePrimitive::colors() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_list:dai.schemas.LinePrimitive.colors)
  return _internal_colors();
}
inline const ::google::protobuf::RepeatedPtrField<::dai::schemas::Color>&
LinePrimitive::_internal_colors() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.colors_;
}
inline ::google::protobuf::RepeatedPtrField<::dai::schemas::Color>*
LinePrimitive::_internal_mutable_colors() {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return &_impl_.colors_;
}

// repeated fixed32 indices = 8;
inline int LinePrimitive::_internal_indices_size() const {
  return _internal_indices().size();
}
inline int LinePrimitive::indices_size() const {
  return _internal_indices_size();
}
inline void LinePrimitive::clear_indices() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.indices_.Clear();
}
inline ::uint32_t LinePrimitive::indices(int index) const {
  // @@protoc_insertion_point(field_get:dai.schemas.LinePrimitive.indices)
  return _internal_indices().Get(index);
}
inline void LinePrimitive::set_indices(int index, ::uint32_t value) {
  _internal_mutable_indices()->Set(index, value);
  // @@protoc_insertion_point(field_set:dai.schemas.LinePrimitive.indices)
}
inline void LinePrimitive::add_indices(::uint32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _internal_mutable_indices()->Add(value);
  // @@protoc_insertion_point(field_add:dai.schemas.LinePrimitive.indices)
}
inline const ::google::protobuf::RepeatedField<::uint32_t>& LinePrimitive::indices() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_list:dai.schemas.LinePrimitive.indices)
  return _internal_indices();
}
inline ::google::protobuf::RepeatedField<::uint32_t>* LinePrimitive::mutable_indices()
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable_list:dai.schemas.LinePrimitive.indices)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  return _internal_mutable_indices();
}
inline const ::google::protobuf::RepeatedField<::uint32_t>& LinePrimitive::_internal_indices()
    const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.indices_;
}
inline ::google::protobuf::RepeatedField<::uint32_t>* LinePrimitive::_internal_mutable_indices() {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return &_impl_.indices_;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace schemas
}  // namespace dai


namespace google {
namespace protobuf {

template <>
struct is_proto_enum<::dai::schemas::LinePrimitive_Type> : std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor<::dai::schemas::LinePrimitive_Type>() {
  return ::dai::schemas::LinePrimitive_Type_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_daischemas_2fLinePrimitive_2eproto_2epb_2eh
