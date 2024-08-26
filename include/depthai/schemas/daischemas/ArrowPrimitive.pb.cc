// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: daischemas/ArrowPrimitive.proto

#include "daischemas/ArrowPrimitive.pb.h"

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

inline constexpr ArrowPrimitive::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        pose_{nullptr},
        color_{nullptr},
        shaft_length_{0},
        shaft_diameter_{0},
        head_length_{0},
        head_diameter_{0} {}

template <typename>
PROTOBUF_CONSTEXPR ArrowPrimitive::ArrowPrimitive(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct ArrowPrimitiveDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ArrowPrimitiveDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~ArrowPrimitiveDefaultTypeInternal() {}
  union {
    ArrowPrimitive _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ArrowPrimitiveDefaultTypeInternal _ArrowPrimitive_default_instance_;
}  // namespace schemas
}  // namespace dai
static ::_pb::Metadata file_level_metadata_daischemas_2fArrowPrimitive_2eproto[1];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_daischemas_2fArrowPrimitive_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_daischemas_2fArrowPrimitive_2eproto = nullptr;
const ::uint32_t TableStruct_daischemas_2fArrowPrimitive_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    PROTOBUF_FIELD_OFFSET(::dai::schemas::ArrowPrimitive, _impl_._has_bits_),
    PROTOBUF_FIELD_OFFSET(::dai::schemas::ArrowPrimitive, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::dai::schemas::ArrowPrimitive, _impl_.pose_),
    PROTOBUF_FIELD_OFFSET(::dai::schemas::ArrowPrimitive, _impl_.shaft_length_),
    PROTOBUF_FIELD_OFFSET(::dai::schemas::ArrowPrimitive, _impl_.shaft_diameter_),
    PROTOBUF_FIELD_OFFSET(::dai::schemas::ArrowPrimitive, _impl_.head_length_),
    PROTOBUF_FIELD_OFFSET(::dai::schemas::ArrowPrimitive, _impl_.head_diameter_),
    PROTOBUF_FIELD_OFFSET(::dai::schemas::ArrowPrimitive, _impl_.color_),
    0,
    ~0u,
    ~0u,
    ~0u,
    ~0u,
    1,
};

static const ::_pbi::MigrationSchema
    schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        {0, 14, -1, sizeof(::dai::schemas::ArrowPrimitive)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::dai::schemas::_ArrowPrimitive_default_instance_._instance,
};
const char descriptor_table_protodef_daischemas_2fArrowPrimitive_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    "\n\037daischemas/ArrowPrimitive.proto\022\013dai.s"
    "chemas\032\026daischemas/Color.proto\032\025daischem"
    "as/Pose.proto\"\256\001\n\016ArrowPrimitive\022\037\n\004pose"
    "\030\001 \001(\0132\021.dai.schemas.Pose\022\024\n\014shaft_lengt"
    "h\030\002 \001(\001\022\026\n\016shaft_diameter\030\003 \001(\001\022\023\n\013head_"
    "length\030\004 \001(\001\022\025\n\rhead_diameter\030\005 \001(\001\022!\n\005c"
    "olor\030\006 \001(\0132\022.dai.schemas.Colorb\006proto3"
};
static const ::_pbi::DescriptorTable* const descriptor_table_daischemas_2fArrowPrimitive_2eproto_deps[2] =
    {
        &::descriptor_table_daischemas_2fColor_2eproto,
        &::descriptor_table_daischemas_2fPose_2eproto,
};
static ::absl::once_flag descriptor_table_daischemas_2fArrowPrimitive_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_daischemas_2fArrowPrimitive_2eproto = {
    false,
    false,
    278,
    descriptor_table_protodef_daischemas_2fArrowPrimitive_2eproto,
    "daischemas/ArrowPrimitive.proto",
    &descriptor_table_daischemas_2fArrowPrimitive_2eproto_once,
    descriptor_table_daischemas_2fArrowPrimitive_2eproto_deps,
    2,
    1,
    schemas,
    file_default_instances,
    TableStruct_daischemas_2fArrowPrimitive_2eproto::offsets,
    file_level_metadata_daischemas_2fArrowPrimitive_2eproto,
    file_level_enum_descriptors_daischemas_2fArrowPrimitive_2eproto,
    file_level_service_descriptors_daischemas_2fArrowPrimitive_2eproto,
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
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_daischemas_2fArrowPrimitive_2eproto_getter() {
  return &descriptor_table_daischemas_2fArrowPrimitive_2eproto;
}
// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_daischemas_2fArrowPrimitive_2eproto(&descriptor_table_daischemas_2fArrowPrimitive_2eproto);
namespace dai {
namespace schemas {
// ===================================================================

class ArrowPrimitive::_Internal {
 public:
  using HasBits = decltype(std::declval<ArrowPrimitive>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
    8 * PROTOBUF_FIELD_OFFSET(ArrowPrimitive, _impl_._has_bits_);
  static const ::dai::schemas::Pose& pose(const ArrowPrimitive* msg);
  static void set_has_pose(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static const ::dai::schemas::Color& color(const ArrowPrimitive* msg);
  static void set_has_color(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
};

const ::dai::schemas::Pose& ArrowPrimitive::_Internal::pose(const ArrowPrimitive* msg) {
  return *msg->_impl_.pose_;
}
const ::dai::schemas::Color& ArrowPrimitive::_Internal::color(const ArrowPrimitive* msg) {
  return *msg->_impl_.color_;
}
void ArrowPrimitive::clear_pose() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (_impl_.pose_ != nullptr) _impl_.pose_->Clear();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
void ArrowPrimitive::clear_color() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (_impl_.color_ != nullptr) _impl_.color_->Clear();
  _impl_._has_bits_[0] &= ~0x00000002u;
}
ArrowPrimitive::ArrowPrimitive(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:dai.schemas.ArrowPrimitive)
}
inline PROTOBUF_NDEBUG_INLINE ArrowPrimitive::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : _has_bits_{from._has_bits_},
        _cached_size_{0} {}

ArrowPrimitive::ArrowPrimitive(
    ::google::protobuf::Arena* arena,
    const ArrowPrimitive& from)
    : ::google::protobuf::Message(arena) {
  ArrowPrimitive* const _this = this;
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
               offsetof(Impl_, shaft_length_),
           reinterpret_cast<const char *>(&from._impl_) +
               offsetof(Impl_, shaft_length_),
           offsetof(Impl_, head_diameter_) -
               offsetof(Impl_, shaft_length_) +
               sizeof(Impl_::head_diameter_));

  // @@protoc_insertion_point(copy_constructor:dai.schemas.ArrowPrimitive)
}
inline PROTOBUF_NDEBUG_INLINE ArrowPrimitive::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0} {}

inline void ArrowPrimitive::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, pose_),
           0,
           offsetof(Impl_, head_diameter_) -
               offsetof(Impl_, pose_) +
               sizeof(Impl_::head_diameter_));
}
ArrowPrimitive::~ArrowPrimitive() {
  // @@protoc_insertion_point(destructor:dai.schemas.ArrowPrimitive)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void ArrowPrimitive::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  delete _impl_.pose_;
  delete _impl_.color_;
  _impl_.~Impl_();
}

PROTOBUF_NOINLINE void ArrowPrimitive::Clear() {
// @@protoc_insertion_point(message_clear_start:dai.schemas.ArrowPrimitive)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

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
  ::memset(&_impl_.shaft_length_, 0, static_cast<::size_t>(
      reinterpret_cast<char*>(&_impl_.head_diameter_) -
      reinterpret_cast<char*>(&_impl_.shaft_length_)) + sizeof(_impl_.head_diameter_));
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* ArrowPrimitive::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<3, 6, 2, 0, 2> ArrowPrimitive::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(ArrowPrimitive, _impl_._has_bits_),
    0, // no _extensions_
    6, 56,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967232,  // skipmap
    offsetof(decltype(_table_), field_entries),
    6,  // num_field_entries
    2,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    &_ArrowPrimitive_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
  }, {{
    {::_pbi::TcParser::MiniParse, {}},
    // .dai.schemas.Pose pose = 1;
    {::_pbi::TcParser::FastMtS1,
     {10, 0, 0, PROTOBUF_FIELD_OFFSET(ArrowPrimitive, _impl_.pose_)}},
    // double shaft_length = 2;
    {::_pbi::TcParser::FastF64S1,
     {17, 63, 0, PROTOBUF_FIELD_OFFSET(ArrowPrimitive, _impl_.shaft_length_)}},
    // double shaft_diameter = 3;
    {::_pbi::TcParser::FastF64S1,
     {25, 63, 0, PROTOBUF_FIELD_OFFSET(ArrowPrimitive, _impl_.shaft_diameter_)}},
    // double head_length = 4;
    {::_pbi::TcParser::FastF64S1,
     {33, 63, 0, PROTOBUF_FIELD_OFFSET(ArrowPrimitive, _impl_.head_length_)}},
    // double head_diameter = 5;
    {::_pbi::TcParser::FastF64S1,
     {41, 63, 0, PROTOBUF_FIELD_OFFSET(ArrowPrimitive, _impl_.head_diameter_)}},
    // .dai.schemas.Color color = 6;
    {::_pbi::TcParser::FastMtS1,
     {50, 1, 1, PROTOBUF_FIELD_OFFSET(ArrowPrimitive, _impl_.color_)}},
    {::_pbi::TcParser::MiniParse, {}},
  }}, {{
    65535, 65535
  }}, {{
    // .dai.schemas.Pose pose = 1;
    {PROTOBUF_FIELD_OFFSET(ArrowPrimitive, _impl_.pose_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kMessage | ::_fl::kTvTable)},
    // double shaft_length = 2;
    {PROTOBUF_FIELD_OFFSET(ArrowPrimitive, _impl_.shaft_length_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kDouble)},
    // double shaft_diameter = 3;
    {PROTOBUF_FIELD_OFFSET(ArrowPrimitive, _impl_.shaft_diameter_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kDouble)},
    // double head_length = 4;
    {PROTOBUF_FIELD_OFFSET(ArrowPrimitive, _impl_.head_length_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kDouble)},
    // double head_diameter = 5;
    {PROTOBUF_FIELD_OFFSET(ArrowPrimitive, _impl_.head_diameter_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kDouble)},
    // .dai.schemas.Color color = 6;
    {PROTOBUF_FIELD_OFFSET(ArrowPrimitive, _impl_.color_), _Internal::kHasBitsOffset + 1, 1,
    (0 | ::_fl::kFcOptional | ::_fl::kMessage | ::_fl::kTvTable)},
  }}, {{
    {::_pbi::TcParser::GetTable<::dai::schemas::Pose>()},
    {::_pbi::TcParser::GetTable<::dai::schemas::Color>()},
  }}, {{
  }},
};

::uint8_t* ArrowPrimitive::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:dai.schemas.ArrowPrimitive)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  // .dai.schemas.Pose pose = 1;
  if (cached_has_bits & 0x00000001u) {
    target = ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
        1, _Internal::pose(this),
        _Internal::pose(this).GetCachedSize(), target, stream);
  }

  // double shaft_length = 2;
  static_assert(sizeof(::uint64_t) == sizeof(double),
                "Code assumes ::uint64_t and double are the same size.");
  double tmp_shaft_length = this->_internal_shaft_length();
  ::uint64_t raw_shaft_length;
  memcpy(&raw_shaft_length, &tmp_shaft_length, sizeof(tmp_shaft_length));
  if (raw_shaft_length != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(
        2, this->_internal_shaft_length(), target);
  }

  // double shaft_diameter = 3;
  static_assert(sizeof(::uint64_t) == sizeof(double),
                "Code assumes ::uint64_t and double are the same size.");
  double tmp_shaft_diameter = this->_internal_shaft_diameter();
  ::uint64_t raw_shaft_diameter;
  memcpy(&raw_shaft_diameter, &tmp_shaft_diameter, sizeof(tmp_shaft_diameter));
  if (raw_shaft_diameter != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(
        3, this->_internal_shaft_diameter(), target);
  }

  // double head_length = 4;
  static_assert(sizeof(::uint64_t) == sizeof(double),
                "Code assumes ::uint64_t and double are the same size.");
  double tmp_head_length = this->_internal_head_length();
  ::uint64_t raw_head_length;
  memcpy(&raw_head_length, &tmp_head_length, sizeof(tmp_head_length));
  if (raw_head_length != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(
        4, this->_internal_head_length(), target);
  }

  // double head_diameter = 5;
  static_assert(sizeof(::uint64_t) == sizeof(double),
                "Code assumes ::uint64_t and double are the same size.");
  double tmp_head_diameter = this->_internal_head_diameter();
  ::uint64_t raw_head_diameter;
  memcpy(&raw_head_diameter, &tmp_head_diameter, sizeof(tmp_head_diameter));
  if (raw_head_diameter != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(
        5, this->_internal_head_diameter(), target);
  }

  // .dai.schemas.Color color = 6;
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
        6, _Internal::color(this),
        _Internal::color(this).GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:dai.schemas.ArrowPrimitive)
  return target;
}

::size_t ArrowPrimitive::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:dai.schemas.ArrowPrimitive)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    // .dai.schemas.Pose pose = 1;
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
  // double shaft_length = 2;
  static_assert(sizeof(::uint64_t) == sizeof(double),
                "Code assumes ::uint64_t and double are the same size.");
  double tmp_shaft_length = this->_internal_shaft_length();
  ::uint64_t raw_shaft_length;
  memcpy(&raw_shaft_length, &tmp_shaft_length, sizeof(tmp_shaft_length));
  if (raw_shaft_length != 0) {
    total_size += 9;
  }

  // double shaft_diameter = 3;
  static_assert(sizeof(::uint64_t) == sizeof(double),
                "Code assumes ::uint64_t and double are the same size.");
  double tmp_shaft_diameter = this->_internal_shaft_diameter();
  ::uint64_t raw_shaft_diameter;
  memcpy(&raw_shaft_diameter, &tmp_shaft_diameter, sizeof(tmp_shaft_diameter));
  if (raw_shaft_diameter != 0) {
    total_size += 9;
  }

  // double head_length = 4;
  static_assert(sizeof(::uint64_t) == sizeof(double),
                "Code assumes ::uint64_t and double are the same size.");
  double tmp_head_length = this->_internal_head_length();
  ::uint64_t raw_head_length;
  memcpy(&raw_head_length, &tmp_head_length, sizeof(tmp_head_length));
  if (raw_head_length != 0) {
    total_size += 9;
  }

  // double head_diameter = 5;
  static_assert(sizeof(::uint64_t) == sizeof(double),
                "Code assumes ::uint64_t and double are the same size.");
  double tmp_head_diameter = this->_internal_head_diameter();
  ::uint64_t raw_head_diameter;
  memcpy(&raw_head_diameter, &tmp_head_diameter, sizeof(tmp_head_diameter));
  if (raw_head_diameter != 0) {
    total_size += 9;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::google::protobuf::Message::ClassData ArrowPrimitive::_class_data_ = {
    ArrowPrimitive::MergeImpl,
    nullptr,  // OnDemandRegisterArenaDtor
};
const ::google::protobuf::Message::ClassData* ArrowPrimitive::GetClassData() const {
  return &_class_data_;
}

void ArrowPrimitive::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<ArrowPrimitive*>(&to_msg);
  auto& from = static_cast<const ArrowPrimitive&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:dai.schemas.ArrowPrimitive)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

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
  static_assert(sizeof(::uint64_t) == sizeof(double),
                "Code assumes ::uint64_t and double are the same size.");
  double tmp_shaft_length = from._internal_shaft_length();
  ::uint64_t raw_shaft_length;
  memcpy(&raw_shaft_length, &tmp_shaft_length, sizeof(tmp_shaft_length));
  if (raw_shaft_length != 0) {
    _this->_internal_set_shaft_length(from._internal_shaft_length());
  }
  static_assert(sizeof(::uint64_t) == sizeof(double),
                "Code assumes ::uint64_t and double are the same size.");
  double tmp_shaft_diameter = from._internal_shaft_diameter();
  ::uint64_t raw_shaft_diameter;
  memcpy(&raw_shaft_diameter, &tmp_shaft_diameter, sizeof(tmp_shaft_diameter));
  if (raw_shaft_diameter != 0) {
    _this->_internal_set_shaft_diameter(from._internal_shaft_diameter());
  }
  static_assert(sizeof(::uint64_t) == sizeof(double),
                "Code assumes ::uint64_t and double are the same size.");
  double tmp_head_length = from._internal_head_length();
  ::uint64_t raw_head_length;
  memcpy(&raw_head_length, &tmp_head_length, sizeof(tmp_head_length));
  if (raw_head_length != 0) {
    _this->_internal_set_head_length(from._internal_head_length());
  }
  static_assert(sizeof(::uint64_t) == sizeof(double),
                "Code assumes ::uint64_t and double are the same size.");
  double tmp_head_diameter = from._internal_head_diameter();
  ::uint64_t raw_head_diameter;
  memcpy(&raw_head_diameter, &tmp_head_diameter, sizeof(tmp_head_diameter));
  if (raw_head_diameter != 0) {
    _this->_internal_set_head_diameter(from._internal_head_diameter());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void ArrowPrimitive::CopyFrom(const ArrowPrimitive& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:dai.schemas.ArrowPrimitive)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool ArrowPrimitive::IsInitialized() const {
  return true;
}

::_pbi::CachedSize* ArrowPrimitive::AccessCachedSize() const {
  return &_impl_._cached_size_;
}
void ArrowPrimitive::InternalSwap(ArrowPrimitive* PROTOBUF_RESTRICT other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(ArrowPrimitive, _impl_.head_diameter_)
      + sizeof(ArrowPrimitive::_impl_.head_diameter_)
      - PROTOBUF_FIELD_OFFSET(ArrowPrimitive, _impl_.pose_)>(
          reinterpret_cast<char*>(&_impl_.pose_),
          reinterpret_cast<char*>(&other->_impl_.pose_));
}

::google::protobuf::Metadata ArrowPrimitive::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_daischemas_2fArrowPrimitive_2eproto_getter, &descriptor_table_daischemas_2fArrowPrimitive_2eproto_once,
      file_level_metadata_daischemas_2fArrowPrimitive_2eproto[0]);
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
