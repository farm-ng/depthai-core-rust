// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: daischemas/LinePrimitive.proto

#include "daischemas/LinePrimitive.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
#include "google/protobuf/generated_message_tctable_impl.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace dai {
namespace schemas {

inline constexpr LinePrimitive::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        points_{},
        colors_{},
        indices_{},
        pose_{nullptr},
        color_{nullptr},
        type_{static_cast< ::dai::schemas::LinePrimitive_Type >(0)},
        scale_invariant_{false},
        thickness_{0} {}

template <typename>
PROTOBUF_CONSTEXPR LinePrimitive::LinePrimitive(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct LinePrimitiveDefaultTypeInternal {
  PROTOBUF_CONSTEXPR LinePrimitiveDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~LinePrimitiveDefaultTypeInternal() {}
  union {
    LinePrimitive _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 LinePrimitiveDefaultTypeInternal _LinePrimitive_default_instance_;
}  // namespace schemas
}  // namespace dai
static ::_pb::Metadata file_level_metadata_daischemas_2fLinePrimitive_2eproto[1];
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_daischemas_2fLinePrimitive_2eproto[1];
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_daischemas_2fLinePrimitive_2eproto = nullptr;
const ::uint32_t TableStruct_daischemas_2fLinePrimitive_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    PROTOBUF_FIELD_OFFSET(::dai::schemas::LinePrimitive, _impl_._has_bits_),
    PROTOBUF_FIELD_OFFSET(::dai::schemas::LinePrimitive, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::dai::schemas::LinePrimitive, _impl_.type_),
    PROTOBUF_FIELD_OFFSET(::dai::schemas::LinePrimitive, _impl_.pose_),
    PROTOBUF_FIELD_OFFSET(::dai::schemas::LinePrimitive, _impl_.thickness_),
    PROTOBUF_FIELD_OFFSET(::dai::schemas::LinePrimitive, _impl_.scale_invariant_),
    PROTOBUF_FIELD_OFFSET(::dai::schemas::LinePrimitive, _impl_.points_),
    PROTOBUF_FIELD_OFFSET(::dai::schemas::LinePrimitive, _impl_.color_),
    PROTOBUF_FIELD_OFFSET(::dai::schemas::LinePrimitive, _impl_.colors_),
    PROTOBUF_FIELD_OFFSET(::dai::schemas::LinePrimitive, _impl_.indices_),
    ~0u,
    0,
    ~0u,
    ~0u,
    ~0u,
    1,
    ~0u,
    ~0u,
};

static const ::_pbi::MigrationSchema
    schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        {0, 16, -1, sizeof(::dai::schemas::LinePrimitive)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::dai::schemas::_LinePrimitive_default_instance_._instance,
};
const char descriptor_table_protodef_daischemas_2fLinePrimitive_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    "\n\036daischemas/LinePrimitive.proto\022\013dai.sc"
    "hemas\032\026daischemas/Color.proto\032\027daischema"
    "s/Point3.proto\032\025daischemas/Pose.proto\"\276\002"
    "\n\rLinePrimitive\022-\n\004type\030\001 \001(\0162\037.dai.sche"
    "mas.LinePrimitive.Type\022\037\n\004pose\030\002 \001(\0132\021.d"
    "ai.schemas.Pose\022\021\n\tthickness\030\003 \001(\001\022\027\n\017sc"
    "ale_invariant\030\004 \001(\010\022#\n\006points\030\005 \003(\0132\023.da"
    "i.schemas.Point3\022!\n\005color\030\006 \001(\0132\022.dai.sc"
    "hemas.Color\022\"\n\006colors\030\007 \003(\0132\022.dai.schema"
    "s.Color\022\017\n\007indices\030\010 \003(\007\"4\n\004Type\022\016\n\nLINE"
    "_STRIP\020\000\022\r\n\tLINE_LOOP\020\001\022\r\n\tLINE_LIST\020\002b\006"
    "proto3"
};
static const ::_pbi::DescriptorTable* const descriptor_table_daischemas_2fLinePrimitive_2eproto_deps[3] =
    {
        &::descriptor_table_daischemas_2fColor_2eproto,
        &::descriptor_table_daischemas_2fPoint3_2eproto,
        &::descriptor_table_daischemas_2fPose_2eproto,
};
static ::absl::once_flag descriptor_table_daischemas_2fLinePrimitive_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_daischemas_2fLinePrimitive_2eproto = {
    false,
    false,
    446,
    descriptor_table_protodef_daischemas_2fLinePrimitive_2eproto,
    "daischemas/LinePrimitive.proto",
    &descriptor_table_daischemas_2fLinePrimitive_2eproto_once,
    descriptor_table_daischemas_2fLinePrimitive_2eproto_deps,
    3,
    1,
    schemas,
    file_default_instances,
    TableStruct_daischemas_2fLinePrimitive_2eproto::offsets,
    file_level_metadata_daischemas_2fLinePrimitive_2eproto,
    file_level_enum_descriptors_daischemas_2fLinePrimitive_2eproto,
    file_level_service_descriptors_daischemas_2fLinePrimitive_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_daischemas_2fLinePrimitive_2eproto_getter() {
  return &descriptor_table_daischemas_2fLinePrimitive_2eproto;
}
// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_daischemas_2fLinePrimitive_2eproto(&descriptor_table_daischemas_2fLinePrimitive_2eproto);
namespace dai {
namespace schemas {
const ::google::protobuf::EnumDescriptor* LinePrimitive_Type_descriptor() {
  ::google::protobuf::internal::AssignDescriptors(&descriptor_table_daischemas_2fLinePrimitive_2eproto);
  return file_level_enum_descriptors_daischemas_2fLinePrimitive_2eproto[0];
}
PROTOBUF_CONSTINIT const uint32_t LinePrimitive_Type_internal_data_[] = {
    196608u, 0u, };
bool LinePrimitive_Type_IsValid(int value) {
  return 0 <= value && value <= 2;
}
#if (__cplusplus < 201703) && \
  (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))

constexpr LinePrimitive_Type LinePrimitive::LINE_STRIP;
constexpr LinePrimitive_Type LinePrimitive::LINE_LOOP;
constexpr LinePrimitive_Type LinePrimitive::LINE_LIST;
constexpr LinePrimitive_Type LinePrimitive::Type_MIN;
constexpr LinePrimitive_Type LinePrimitive::Type_MAX;
constexpr int LinePrimitive::Type_ARRAYSIZE;

#endif  // (__cplusplus < 201703) &&
        // (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
// ===================================================================

class LinePrimitive::_Internal {
 public:
  using HasBits = decltype(std::declval<LinePrimitive>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
    8 * PROTOBUF_FIELD_OFFSET(LinePrimitive, _impl_._has_bits_);
  static const ::dai::schemas::Pose& pose(const LinePrimitive* msg);
  static void set_has_pose(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static const ::dai::schemas::Color& color(const LinePrimitive* msg);
  static void set_has_color(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
};

const ::dai::schemas::Pose& LinePrimitive::_Internal::pose(const LinePrimitive* msg) {
  return *msg->_impl_.pose_;
}
const ::dai::schemas::Color& LinePrimitive::_Internal::color(const LinePrimitive* msg) {
  return *msg->_impl_.color_;
}
void LinePrimitive::clear_pose() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (_impl_.pose_ != nullptr) _impl_.pose_->Clear();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
void LinePrimitive::clear_points() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.points_.Clear();
}
void LinePrimitive::clear_color() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (_impl_.color_ != nullptr) _impl_.color_->Clear();
  _impl_._has_bits_[0] &= ~0x00000002u;
}
void LinePrimitive::clear_colors() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.colors_.Clear();
}
LinePrimitive::LinePrimitive(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:dai.schemas.LinePrimitive)
}
inline PROTOBUF_NDEBUG_INLINE LinePrimitive::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : _has_bits_{from._has_bits_},
        _cached_size_{0},
        points_{visibility, arena, from.points_},
        colors_{visibility, arena, from.colors_},
        indices_{visibility, arena, from.indices_} {}

LinePrimitive::LinePrimitive(
    ::google::protobuf::Arena* arena,
    const LinePrimitive& from)
    : ::google::protobuf::Message(arena) {
  LinePrimitive* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);
  ::uint32_t cached_has_bits = _impl_._has_bits_[0];
  _impl_.pose_ = (cached_has_bits & 0x00000001u)
                ? CreateMaybeMessage<::dai::schemas::Pose>(arena, *from._impl_.pose_)
                : nullptr;
  _impl_.color_ = (cached_has_bits & 0x00000002u)
                ? CreateMaybeMessage<::dai::schemas::Color>(arena, *from._impl_.color_)
                : nullptr;
  ::memcpy(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, type_),
           reinterpret_cast<const char *>(&from._impl_) +
               offsetof(Impl_, type_),
           offsetof(Impl_, thickness_) -
               offsetof(Impl_, type_) +
               sizeof(Impl_::thickness_));

  // @@protoc_insertion_point(copy_constructor:dai.schemas.LinePrimitive)
}
inline PROTOBUF_NDEBUG_INLINE LinePrimitive::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0},
        points_{visibility, arena},
        colors_{visibility, arena},
        indices_{visibility, arena} {}

inline void LinePrimitive::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, pose_),
           0,
           offsetof(Impl_, thickness_) -
               offsetof(Impl_, pose_) +
               sizeof(Impl_::thickness_));
}
LinePrimitive::~LinePrimitive() {
  // @@protoc_insertion_point(destructor:dai.schemas.LinePrimitive)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void LinePrimitive::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  delete _impl_.pose_;
  delete _impl_.color_;
  _impl_.~Impl_();
}

PROTOBUF_NOINLINE void LinePrimitive::Clear() {
// @@protoc_insertion_point(message_clear_start:dai.schemas.LinePrimitive)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.points_.Clear();
  _impl_.colors_.Clear();
  _impl_.indices_.Clear();
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      ABSL_DCHECK(_impl_.pose_ != nullptr);
      _impl_.pose_->Clear();
    }
    if (cached_has_bits & 0x00000002u) {
      ABSL_DCHECK(_impl_.color_ != nullptr);
      _impl_.color_->Clear();
    }
  }
  ::memset(&_impl_.type_, 0, static_cast<::size_t>(
      reinterpret_cast<char*>(&_impl_.thickness_) -
      reinterpret_cast<char*>(&_impl_.type_)) + sizeof(_impl_.thickness_));
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* LinePrimitive::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<3, 8, 4, 0, 2> LinePrimitive::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(LinePrimitive, _impl_._has_bits_),
    0, // no _extensions_
    8, 56,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967040,  // skipmap
    offsetof(decltype(_table_), field_entries),
    8,  // num_field_entries
    4,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    &_LinePrimitive_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
  }, {{
    // repeated fixed32 indices = 8;
    {::_pbi::TcParser::FastF32P1,
     {66, 63, 0, PROTOBUF_FIELD_OFFSET(LinePrimitive, _impl_.indices_)}},
    // .dai.schemas.LinePrimitive.Type type = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(LinePrimitive, _impl_.type_), 63>(),
     {8, 63, 0, PROTOBUF_FIELD_OFFSET(LinePrimitive, _impl_.type_)}},
    // .dai.schemas.Pose pose = 2;
    {::_pbi::TcParser::FastMtS1,
     {18, 0, 0, PROTOBUF_FIELD_OFFSET(LinePrimitive, _impl_.pose_)}},
    // double thickness = 3;
    {::_pbi::TcParser::FastF64S1,
     {25, 63, 0, PROTOBUF_FIELD_OFFSET(LinePrimitive, _impl_.thickness_)}},
    // bool scale_invariant = 4;
    {::_pbi::TcParser::SingularVarintNoZag1<bool, offsetof(LinePrimitive, _impl_.scale_invariant_), 63>(),
     {32, 63, 0, PROTOBUF_FIELD_OFFSET(LinePrimitive, _impl_.scale_invariant_)}},
    // repeated .dai.schemas.Point3 points = 5;
    {::_pbi::TcParser::FastMtR1,
     {42, 63, 1, PROTOBUF_FIELD_OFFSET(LinePrimitive, _impl_.points_)}},
    // .dai.schemas.Color color = 6;
    {::_pbi::TcParser::FastMtS1,
     {50, 1, 2, PROTOBUF_FIELD_OFFSET(LinePrimitive, _impl_.color_)}},
    // repeated .dai.schemas.Color colors = 7;
    {::_pbi::TcParser::FastMtR1,
     {58, 63, 3, PROTOBUF_FIELD_OFFSET(LinePrimitive, _impl_.colors_)}},
  }}, {{
    65535, 65535
  }}, {{
    // .dai.schemas.LinePrimitive.Type type = 1;
    {PROTOBUF_FIELD_OFFSET(LinePrimitive, _impl_.type_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kOpenEnum)},
    // .dai.schemas.Pose pose = 2;
    {PROTOBUF_FIELD_OFFSET(LinePrimitive, _impl_.pose_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kMessage | ::_fl::kTvTable)},
    // double thickness = 3;
    {PROTOBUF_FIELD_OFFSET(LinePrimitive, _impl_.thickness_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kDouble)},
    // bool scale_invariant = 4;
    {PROTOBUF_FIELD_OFFSET(LinePrimitive, _impl_.scale_invariant_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kBool)},
    // repeated .dai.schemas.Point3 points = 5;
    {PROTOBUF_FIELD_OFFSET(LinePrimitive, _impl_.points_), -1, 1,
    (0 | ::_fl::kFcRepeated | ::_fl::kMessage | ::_fl::kTvTable)},
    // .dai.schemas.Color color = 6;
    {PROTOBUF_FIELD_OFFSET(LinePrimitive, _impl_.color_), _Internal::kHasBitsOffset + 1, 2,
    (0 | ::_fl::kFcOptional | ::_fl::kMessage | ::_fl::kTvTable)},
    // repeated .dai.schemas.Color colors = 7;
    {PROTOBUF_FIELD_OFFSET(LinePrimitive, _impl_.colors_), -1, 3,
    (0 | ::_fl::kFcRepeated | ::_fl::kMessage | ::_fl::kTvTable)},
    // repeated fixed32 indices = 8;
    {PROTOBUF_FIELD_OFFSET(LinePrimitive, _impl_.indices_), -1, 0,
    (0 | ::_fl::kFcRepeated | ::_fl::kPackedFixed32)},
  }}, {{
    {::_pbi::TcParser::GetTable<::dai::schemas::Pose>()},
    {::_pbi::TcParser::GetTable<::dai::schemas::Point3>()},
    {::_pbi::TcParser::GetTable<::dai::schemas::Color>()},
    {::_pbi::TcParser::GetTable<::dai::schemas::Color>()},
  }}, {{
  }},
};

::uint8_t* LinePrimitive::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:dai.schemas.LinePrimitive)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // .dai.schemas.LinePrimitive.Type type = 1;
  if (this->_internal_type() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
        1, this->_internal_type(), target);
  }

  cached_has_bits = _impl_._has_bits_[0];
  // .dai.schemas.Pose pose = 2;
  if (cached_has_bits & 0x00000001u) {
    target = ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
        2, _Internal::pose(this),
        _Internal::pose(this).GetCachedSize(), target, stream);
  }

  // double thickness = 3;
  static_assert(sizeof(::uint64_t) == sizeof(double),
                "Code assumes ::uint64_t and double are the same size.");
  double tmp_thickness = this->_internal_thickness();
  ::uint64_t raw_thickness;
  memcpy(&raw_thickness, &tmp_thickness, sizeof(tmp_thickness));
  if (raw_thickness != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(
        3, this->_internal_thickness(), target);
  }

  // bool scale_invariant = 4;
  if (this->_internal_scale_invariant() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(
        4, this->_internal_scale_invariant(), target);
  }

  // repeated .dai.schemas.Point3 points = 5;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_points_size()); i < n; i++) {
    const auto& repfield = this->_internal_points().Get(i);
    target = ::google::protobuf::internal::WireFormatLite::
        InternalWriteMessage(5, repfield, repfield.GetCachedSize(), target, stream);
  }

  // .dai.schemas.Color color = 6;
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
        6, _Internal::color(this),
        _Internal::color(this).GetCachedSize(), target, stream);
  }

  // repeated .dai.schemas.Color colors = 7;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_colors_size()); i < n; i++) {
    const auto& repfield = this->_internal_colors().Get(i);
    target = ::google::protobuf::internal::WireFormatLite::
        InternalWriteMessage(7, repfield, repfield.GetCachedSize(), target, stream);
  }

  // repeated fixed32 indices = 8;
  if (this->_internal_indices_size() > 0) {
    target = stream->WriteFixedPacked(8, _internal_indices(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:dai.schemas.LinePrimitive)
  return target;
}

::size_t LinePrimitive::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:dai.schemas.LinePrimitive)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .dai.schemas.Point3 points = 5;
  total_size += 1UL * this->_internal_points_size();
  for (const auto& msg : this->_internal_points()) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSize(msg);
  }
  // repeated .dai.schemas.Color colors = 7;
  total_size += 1UL * this->_internal_colors_size();
  for (const auto& msg : this->_internal_colors()) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSize(msg);
  }
  // repeated fixed32 indices = 8;
  {
    std::size_t data_size = std::size_t{4} *
        ::_pbi::FromIntSize(this->_internal_indices_size())
    ;
    std::size_t tag_size = data_size == 0
        ? 0
        : 1 + ::_pbi::WireFormatLite::Int32Size(
                            static_cast<int32_t>(data_size))
    ;
    total_size += tag_size + data_size;
  }
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    // .dai.schemas.Pose pose = 2;
    if (cached_has_bits & 0x00000001u) {
      total_size +=
          1 + ::google::protobuf::internal::WireFormatLite::MessageSize(*_impl_.pose_);
    }

    // .dai.schemas.Color color = 6;
    if (cached_has_bits & 0x00000002u) {
      total_size +=
          1 + ::google::protobuf::internal::WireFormatLite::MessageSize(*_impl_.color_);
    }

  }
  // .dai.schemas.LinePrimitive.Type type = 1;
  if (this->_internal_type() != 0) {
    total_size += 1 +
                  ::_pbi::WireFormatLite::EnumSize(this->_internal_type());
  }

  // bool scale_invariant = 4;
  if (this->_internal_scale_invariant() != 0) {
    total_size += 2;
  }

  // double thickness = 3;
  static_assert(sizeof(::uint64_t) == sizeof(double),
                "Code assumes ::uint64_t and double are the same size.");
  double tmp_thickness = this->_internal_thickness();
  ::uint64_t raw_thickness;
  memcpy(&raw_thickness, &tmp_thickness, sizeof(tmp_thickness));
  if (raw_thickness != 0) {
    total_size += 9;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::google::protobuf::Message::ClassData LinePrimitive::_class_data_ = {
    LinePrimitive::MergeImpl,
    nullptr,  // OnDemandRegisterArenaDtor
};
const ::google::protobuf::Message::ClassData* LinePrimitive::GetClassData() const {
  return &_class_data_;
}

void LinePrimitive::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<LinePrimitive*>(&to_msg);
  auto& from = static_cast<const LinePrimitive&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:dai.schemas.LinePrimitive)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_internal_mutable_points()->MergeFrom(
      from._internal_points());
  _this->_internal_mutable_colors()->MergeFrom(
      from._internal_colors());
  _this->_internal_mutable_indices()->MergeFrom(from._internal_indices());
  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _this->_internal_mutable_pose()->::dai::schemas::Pose::MergeFrom(
          from._internal_pose());
    }
    if (cached_has_bits & 0x00000002u) {
      _this->_internal_mutable_color()->::dai::schemas::Color::MergeFrom(
          from._internal_color());
    }
  }
  if (from._internal_type() != 0) {
    _this->_internal_set_type(from._internal_type());
  }
  if (from._internal_scale_invariant() != 0) {
    _this->_internal_set_scale_invariant(from._internal_scale_invariant());
  }
  static_assert(sizeof(::uint64_t) == sizeof(double),
                "Code assumes ::uint64_t and double are the same size.");
  double tmp_thickness = from._internal_thickness();
  ::uint64_t raw_thickness;
  memcpy(&raw_thickness, &tmp_thickness, sizeof(tmp_thickness));
  if (raw_thickness != 0) {
    _this->_internal_set_thickness(from._internal_thickness());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void LinePrimitive::CopyFrom(const LinePrimitive& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:dai.schemas.LinePrimitive)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool LinePrimitive::IsInitialized() const {
  return true;
}

::_pbi::CachedSize* LinePrimitive::AccessCachedSize() const {
  return &_impl_._cached_size_;
}
void LinePrimitive::InternalSwap(LinePrimitive* PROTOBUF_RESTRICT other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  _impl_.points_.InternalSwap(&other->_impl_.points_);
  _impl_.colors_.InternalSwap(&other->_impl_.colors_);
  _impl_.indices_.InternalSwap(&other->_impl_.indices_);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(LinePrimitive, _impl_.thickness_)
      + sizeof(LinePrimitive::_impl_.thickness_)
      - PROTOBUF_FIELD_OFFSET(LinePrimitive, _impl_.pose_)>(
          reinterpret_cast<char*>(&_impl_.pose_),
          reinterpret_cast<char*>(&other->_impl_.pose_));
}

::google::protobuf::Metadata LinePrimitive::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_daischemas_2fLinePrimitive_2eproto_getter, &descriptor_table_daischemas_2fLinePrimitive_2eproto_once,
      file_level_metadata_daischemas_2fLinePrimitive_2eproto[0]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace schemas
}  // namespace dai
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
#include "google/protobuf/port_undef.inc"
